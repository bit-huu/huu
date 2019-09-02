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
	char GroupNo[GROUP_NO_SIZE];	//�ͻ���������
	char UserName[USER_NAME_SIZE];	//�ͻ����û���
	struct sockaddr_in ServerAddr;	//����˵�ַ

	Client();
	~Client();

	void SendMsg(int GroupNo, char Msg[]);	//������Ϣ
	void RecvMsg();	//������Ϣ
	void SendFile(int GroupNo, char FileRoat[])	//�����ļ�
	void RecvFile();	//�����ļ�

private:
	int MessageSocket;	//��Ϣ�շ��׽���
	int FlieSocket;	//�ļ��շ��׽���
	pthread_t MessageThread, FileThread;	//��Ϣ���ļ��߳�
};

Client::Client(int No, char userName[], char ServerIP[]):UserName(userName)
{
	itoa(No, GroupNo, 10);

	/*�����׽���*/
	MessageSocket = socket(AF_INET, SOCK_STREAM, 0);
	FlieSocket = socket(AF_INET, SOCK_STREAM, 0);

	/*���÷�������ַ*/
	ServerAddr.sin_family = AF_INET;	//ʹ��IPV4ͨ��
	ServerAddr.sin_addr.s_addr = inet_addr(ServerIP);
	ServerAddr.sin_port = htons(8080);	//�˿�

	/*���ӵ�ַ���׽���*/
	connect(MessageSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	connect(FlieSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

	/*�����߳�*/
	pthread_create(&MessageThread, NULL, RecvMsg, (void *) &MessageSocket);
	pthread_create(&FileThread, NULL, RecvFile, (void *) &FlieSocket);
}

Client::~Client()
{
	char ExitInfo[30];
	char SocketNo[5];
	bzero(ExitInfo, BUFFER_SIZE);
	bzero(SocketNo, BUFFER_SIZE);

	/*�����˷����׽��ֹر���Ϣ*/
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

	/*�ر��߳�*/
	pthread_join(MessageThread, NULL);
	pthread_join(FileThread, NULL);

	/*�ر��׽���*/
	close(MessageSocket);
	close(FlieSocket);
}

void Client::SendMsg(char Msg[])
{
	char SendBuffer[BUFFER_SIZE];	//��������Ϣ����
	time_t now = time(0);

	bzero(RecvBuffer, BUFFER_SIZE);

	/*����Ϣ���*/
	strcpy(SendBuffer, GroupNo);
	strcpy(SendBuffer + GROUP_NO_SIZE, UserName);
	strcpy(SendBuffer + GROUP_NO_SIZE + USER_NAME_SIZE, ctime(&now));
	strcpy(SendBuffer + GROUP_NO_SIZE + USER_NAME_SIZE + TIME_SIZE, Msg);

	send(MessageSocket, SendBuffer, BUFFER_SIZE, 0);
}

void Client::RecvMsg()
{
	char RecvBuffer[BUFFER_SIZE];	//������Ϣ����
	char SenderGroup[GROUP_NO_SIZE];//ͨ������
	char SenderName[USER_NAME_SIZE];//����������
	char MsgTimestemp[TIME_SIZE];	//��Ϣʱ���
	char Msg[MSG_SIZE];				//������Ϣ����

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
				֪ͨUI��ʾ��Ϣ
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
			֪ͨUI���ļ�ʧ��
		*/
	}
	else
	{
		char FileBuffer[BUFFER_SIZE];
		int SendLength;

		bzero(FileBuffer, BUFFER_SIZE);

		/*����ļ�·��������*/
		strcpy(FileBuffer, GroupNo);
		strcpy(FileBuffer + GROUP_NO_SIZE, FileRoat);
		send(FlieSocket, FileBuffer, BUFFER_SIZE, 0);

		bzero(FileBuffer, BUFFER_SIZE);

		while ((SendLength = fread(FileBuffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
		{
			if (send(FlieSocket, FileBuffer, SendLength, 0) < 0)
			{
				/*
					֪ͨUI�����ļ�ʧ��
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
			֪ͨUI�ļ����ͽ���
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

			/*���ļ�·������ȡ�ļ���*/
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
				֪ͨUI���û������Ƿ�Ҫ�����ļ�
			*/

			FILE *fp = fopen(FileName, "w");
			if (fp == NULL)
			{
				/*
					֪ͨUI�½��ļ�ʧ��
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
							֪ͨUI�ļ�д���쳣
						*/

						break;
					}
				}
			}

			close(fp);
			bzero(FileRoat, BUFFER_SIZE);

			/*
				֪ͨUI�ļ����ͽ���
			*/
		}
	}
	pthread_exit(NULL);
}

