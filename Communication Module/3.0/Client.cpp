/*************************************************************************
  Developer:
	> Tang Yongxiang
	> Deng Liting

  Buffer Format:
	>Which group, Who, When, send What msg
	>Which group, FileRoat
	>Which group, FileContent
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctime>

const int BUFFER_SIZE = 1000;
const int GROUP_NO_SIZE = 5;
const int USER_NAME_SIZE = 20;
const int TIME_SIZE = 25;
const int FILE_NAME_SIZE = 50;
const int MSG_SIZE = (BUFFER_SIZE - GROUP_NO_SIZE - USER_NAME_SIZE - TIME_SIZE);

class Client
{
public:
	char GroupNo[GROUP_NO_SIZE];	//客户端所在组
	char UserName[USER_NAME_SIZE];	//客户端用户名
	struct sockaddr_in ServerAddr;	//服务端地址

	Client();
	~Client();

	void SendMsg(int GroupNo, char Msg[]);	//发送信息
	void RecvMsg();	//接收信息
	void SendFile(int GroupNo, char FileRoat[])	//发送文件
	void RecvFile();	//接收文件

private:
	int MessageSocket;	//信息收发套接字
	int FlieSocket;	//文件收发套接字
	pthread_t MessageThread, FileThread;	//信息与文件线程
};

Client::Client(int No, char userName[], char ServerIP[]):UserName(userName)
{
	itoa(No, GroupNo, 10);

	/*申请套接字*/
	MessageSocket = socket(AF_INET, SOCK_STREAM, 0);
	FlieSocket = socket(AF_INET, SOCK_STREAM, 0);

	/*设置服务器地址*/
	ServerAddr.sin_family = AF_INET;	//使用IPV4通信
	ServerAddr.sin_addr.s_addr = inet_addr(ServerIP);
	ServerAddr.sin_port = htons(8080);	//端口

	/*连接地址与套接字*/
	connect(MessageSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	connect(FlieSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

	/*创建线程*/
	pthread_create(&MessageThread, NULL, RecvMsg, (void *) &MessageSocket);
	pthread_create(&FileThread, NULL, RecvFile, (void *) &FlieSocket);
}

Client::~Client()
{
	char ExitInfo[30];
	char SocketNo[5];
	bzero(ExitInfo, BUFFER_SIZE);
	bzero(SocketNo, BUFFER_SIZE);

	/*向服务端发送套接字关闭信息*/
	strcpy(ExitInfo, GroupNo);
	strcpy(ExitInfo + GROUP_NO_SIZE, "Socket Exit:");
	itoa(MessageSocket, SocketNo, 10);
	strcpy(ExitInfo + GROUP_NO_SIZE + 12, SocketNo);
	send(MessageSocket, SendBuffer, BUFFER_SIZE, 0);
	strcpy(ExitInfo, GroupNo);
	strcpy(ExitInfo + GROUP_NO_SIZE, "Socket Exit:");
	itoa(FlieSocket, SocketNo, 10);
	strcpy(ExitInfo + GROUP_NO_SIZE + 12, SocketNo);
	send(FlieSocket, SendBuffer, BUFFER_SIZE, 0);

	/*关闭线程*/
	pthread_join(MessageThread, NULL);
	pthread_join(FileThread, NULL);

	/*关闭套接字*/
	close(MessageSocket);
	close(FlieSocket);
}

void Client::SendMsg(char Msg[])
{
	char SendBuffer[BUFFER_SIZE];	//待发送信息缓存
	time_t now = time(0);

	bzero(RecvBuffer, BUFFER_SIZE);

	/*将信息打包*/
	strcpy(SendBuffer, GroupNo);
	strcpy(SendBuffer + GROUP_NO_SIZE, UserName);
	strcpy(SendBuffer + GROUP_NO_SIZE + USER_NAME_SIZE, ctime(&now));
	strcpy(SendBuffer + GROUP_NO_SIZE + USER_NAME_SIZE + TIME_SIZE, Msg);

	send(MessageSocket, SendBuffer, BUFFER_SIZE, 0);
}

void Client::RecvMsg()
{
	char RecvBuffer[BUFFER_SIZE];	//接收信息缓存
	char SenderGroup[GROUP_NO_SIZE];//通信组编号
	char SenderName[USER_NAME_SIZE];//发送者名字
	char MsgTimestemp[TIME_SIZE];	//信息时间戳
	char Msg[MSG_SIZE];				//发送信息内容

	while (1)
	{
		bzero(RecvBuffer, BUFFER_SIZE);

		if (recv(MessageSocket, RecvBuffer, BUFFER_SIZE, 0) > 0)
		{
			bzero(SenderGroup, GROUP_NO_SIZE);
			bzero(SenderName, USER_NAME_SIZE);
			bzero(MsgTimestemp, TIME_SIZE);
			bzero(Msg, MSG_SIZE);

			memcpy(SenderGroup, RecvBuffer, GROUP_NO_SIZE)
			memcpy(SenderName, RecvBuffer + GROUP_NO_SIZE, USER_NAME_SIZE);
			memcpy(MsgTimestemp, RecvBuffer + GROUP_NO_SIZE + USER_NAME_SIZE, TIME_SIZE);
			memcpy(Msg, RecvBuffer + GROUP_NO_SIZE + USER_NAME_SIZE + TIME_SIZE, MSG_SIZE);

			int SenderGroup = atoi(SenderGroup);

			/*
				通知UI显示信息
			*/


		}
	}
	pthread_exit(NULL);
}

void Client::SendFile(char FileRoat[])
{

	FILE *fp = fopen(FileRoat, "r");


	if (fp == NULL)
	{
		/*
			通知UI打开文件失败
		*/
	}
	else
	{
		char FileBuffer[BUFFER_SIZE];
		int SendLength;

		bzero(FileBuffer, BUFFER_SIZE);

		/*打包文件路径并发送*/
		strcpy(FileBuffer, GroupNo);
		strcpy(FileBuffer + GROUP_NO_SIZE, FileRoat);
		send(FlieSocket, FileBuffer, BUFFER_SIZE, 0);

		bzero(FileBuffer, BUFFER_SIZE);

		while ((SendLength = fread(FileBuffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
		{
			if (send(FlieSocket, FileBuffer, SendLength, 0) < 0)
			{
				/*
					通知UI发送文件失败
				*/

				break;
			}
			bzero(FileBuffer, BUFFER_SIZE);
		}

		bzero(FileBuffer, BUFFER_SIZE);
		strcpy(FileBuffer, GroupNo);
		strcpy(FileBuffer + GROUP_NO_SIZE, "Flie transfer complete!");
		send(FlieSocket, FileBuffer, BUFFER_SIZE, 0);
		fclose(fp);

		/*
			通知UI文件传送结束
		*/
	}

}

void Client::RecvFile()
{
	int NameLen = 0;
	char FileRoat[BUFFER_SIZE];
	char FileBuffer[BUFFER_SIZE];
	char FileName[FILE_NAME_SIZE];

	bzero(FileRoat, BUFFER_SIZE);

	while (1)
	{
		if (recv(FlieSocket, FileRoat, BUFFER_SIZE, 0) > 0)
		{
			bzero(FileBuffer, BUFFER_SIZE);
			bzero(FileName, FILE_NAME_SIZE);

			/*从文件路径中提取文件名*/
			int RoatSize = strlen(FileRoat);
			for (int i = RoatSize - 1; strstr({'<', '>' '/' '\\' '|' ':' '\"' '*' '\?'}, FileRoat[i]) == NULL; --i, ++NameLen)
			{
				FileName[NameLen] = FileRoat[i];
			}
			for (int i = 0; i < NameLen / 2; ++i)
			{
				char Temp = FileName[i];
				FileName[i] = FileName[NameLen - i - 1];
				FileName[NameLen - i - 1] = Temp;
			}

			/*
				通知UI让用户决定是否要接收文件
			*/

			FILE *fp = fopen(FileName, "w");
			if (fp == NULL)
			{
				/*
					通知UI新建文件失败
				*/
			}

			int SendLength = 0;
			int SendFlag = 1;

			while (SendFlag)
			{
				while ((SendLength = recv(FlieSocket, FileBuffer, BUFFER_SIZE, 0) - 5) > 0)
				{
					if (!strncmp(FileBuffer + GROUP_NO_SIZE, "Flie transfer complete!", 23))
					{
						SendFlag = 0;
						break;
					}
					else if (fwrite(FileBuffer + GROUP_NO_SIZE, sizeof(char), SendLength, fp) < SendLength)
					{
						/*
							通知UI文件写入异常
						*/

						break;
					}
				}
			}

			close(fp);
			bzero(FileRoat, BUFFER_SIZE);

			/*
				通知UI文件传送结束
			*/
		}
	}
	pthread_exit(NULL);
}

