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

#define BUFFER_SIZE 1000
#define GROUP_NO_SIZE 5
#define USER_NAME_SIZE 20
#define TIME_SIZE 25
#define FILE_NAME_SIZE 50
#define MSG_SIZE (BUFFER_SIZE - GROUP_NO_SIZE - USER_NAME_SIZE - TIME_SIZE)

struct User
{
	char Name[USER_NAME_SIZE];

	/*其他可能需要的信息*/

}ClientUser;	//客户端服务的用户

struct sockaddr_in ServerAddr;	//服务器地址



void SendMsg(int Socket, int GroupNo, char Msg[])
{
	char SendBuffer[BUFFER_SIZE];	//待发送信息缓存
	time_t now = time(0);

	bzero(RecvBuffer, BUFFER_SIZE);

	char SenderGroup[5] = {0};
	itoa(GroupNo, SenderGroup, 10);

	/*将信息打包*/
	strcpy(SendBuffer, SenderGroup);
	strcpy(SendBuffer + GROUP_NO_SIZE, ClientUser.Name);
	strcpy(SendBuffer + GROUP_NO_SIZE + USER_NAME_SIZE, ctime(&now));
	strcpy(SendBuffer + GROUP_NO_SIZE + USER_NAME_SIZE + TIME_SIZE, Msg);

	send(Socket, SendBuffer, BUFFER_SIZE, 0);
}

void RecvMsg(void* _Socket)
{
	int Socket = *((int*) _Socket);	//套接字编号
	char RecvBuffer[BUFFER_SIZE];	//接收信息缓存
	char SenderGroup[GROUP_NO_SIZE];//通信组编号
	char SenderName[USER_NAME_SIZE];//发送者名字
	char MsgTimestemp[TIME_SIZE];	//信息时间戳
	char Msg[MSG_SIZE];				//发送信息内容

	while (1)
	{
		bzero(RecvBuffer, BUFFER_SIZE);

		if (recv(Socket, RecvBuffer, BUFFER_SIZE, 0) > 0)
		{
			bzero(SenderGroup, GROUP_NO_SIZE);
			bzero(SenderName, USER_NAME_SIZE);
			bzero(MsgTimestemp, TIME_SIZE);
			bzero(Msg, MSG_SIZE);

			memcpy(SenderGroup, RecvBuffer, GROUP_NO_SIZE)
			memcpy(SenderName, RecvBuffer + GROUP_NO_SIZE, USER_NAME_SIZE);
			memcpy(MsgTimestemp, RecvBuffer + GROUP_NO_SIZE + USER_NAME_SIZE, TIME_SIZE);
			memcpy(Msg, RecvBuffer + GROUP_NO_SIZE + USER_NAME_SIZE + TIME_SIZE, MSG_SIZE);

			int GroupNo = atoi(SenderGroup);

			/*
				通知UI显示信息
			*/

			
		}

		if ( /*停止接收信息*/ )
		{
			break;
		}
	}
	pthread_exit(NULL);
}

void SendFile(int Socket, int GroupNo, char FileRoat[])
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
		char SenderGroup[GROUP_NO_SIZE] = {0};
		int SendLength;

		bzero(FileBuffer, BUFFER_SIZE);
		bzero(SenderGroup, GROUP_NO_SIZE);

		/*打包文件路径并发送*/
		itoa(GroupNo, SenderGroup, 10);
		strcpy(FileBuffer, SenderGroup);
		strcpy(FileBuffer + GROUP_NO_SIZE, FileRoat);
		send(Socket, FileBuffer, BUFFER_SIZE, 0);

		bzero(FileBuffer, BUFFER_SIZE);

		while ((SendLength = fread(FileBuffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
		{
			if (send(Socket, FileBuffer, SendLength, 0) < 0)
			{
				/*
					通知UI发送文件失败
				*/

				break;
			}
			bzero(FileBuffer, BUFFER_SIZE);
		}

		bzero(FileBuffer, BUFFER_SIZE);
		strcpy(FileBuffer, SenderGroup);
		strcpy(FileBuffer + GROUP_NO_SIZE, "Flie transfer complete!");
		send(Socket, FileBuffer, BUFFER_SIZE, 0);
		fclose(fp);

		/*
			通知UI文件传送结束
		*/
	}

}

void RecvFile(void* _Socket)
{
	int Socket = *((int*) _Socket);	//套接字编号
	int NameLen = 0;
	char FileRoat[BUFFER_SIZE];//文件名缓存
	char FileBuffer[BUFFER_SIZE];
	char FileName[FILE_NAME_SIZE];

	bzero(FileRoat, BUFFER_SIZE);

	while (1)
	{
		if (recv(Socket, FileRoat, BUFFER_SIZE, 0) > 0)
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
				while ((SendLength = recv(Socket, FileBuffer, BUFFER_SIZE, 0) - 5) > 0)
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
}

/*void CloseClient()
{
	
}*/

int main()
{
	/*申请套接字*/
	int MessageSocket = socket(AF_INET, SOCK_STREAM, 0);
	int FlieSocket = socket(AF_INET, SOCK_STREAM, 0);

	/*设置服务器地址*/
	ServerAddr.sin_family = AF_INET;	//IPV4
	ServerAddr.sin_addr.s_addr = inet_addr(/*服务器地址*/);
	ServerAddr.sin_port = htons(8080);	//端口

	/*连接地址与套接字*/
	connect(MessageSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	connect(FlieSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

	/*创建线程*/
	pthread_t MessageThread, FileThread;
	pthread_create(&MessageThread, NULL, RecvMsg, (void *) &MessageSocket);
	pthread_create(&FileThread, NULL, RecvFile, (void *) &FlieSocket);

	/*关闭线程*/
	pthread_join(MessageThread, NULL);
	pthread_join(FileThread, NULL);

	/*关闭套接字*/
	close(MessageSocket);
	close(FlieSocket);
}

