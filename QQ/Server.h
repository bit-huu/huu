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
#include <netinet/in.h>
#include <stdbool.h>

const int BUFFER_SIZE = 1000;
const int GROUP_NO_SIZE = 5;
const int USER_SUM_SIZE = 200;
const int GROUP_SUM_SIZE = 50;

class Server
{
public:
	bool SocketsBox[GROUP_SUM_SIZE][USER_SUM_SIZE];	//��־�����������Ƿ���ĳ���׽���
	struct sockaddr_in ServerAddr;
	int ServerSocket;
	int MaxSocket;

	Server();
	~Server();

	void TransBuffer(void* _Socket);	//��Ϣ��ת
	void ServerOnline();	//���з����

private:

};

Server::Server(char ServerIP[])
{
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	ServerAddr.sin_family = AF_INET;	//ʹ��IPV4ͨ��
	ServerAddr.sin_addr.s_addr = inet_addr(ServerIP);
	ServerAddr.sin_port = htons(8080);	//�˿�

	/*���ӵ�ַ���׽���*/
	bind(ServerSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
}

Server::~Server()
{
	/*�ر��׽���*/
	close(ServerSocket);
}

void Server::TransBuffer(void* _Socket)
{
	int Socket = *((int*) _Socket);
	char Buffer[BUFFER_SIZE];
	char Group[GROUP_NO_SIZE];

	while (1)
	{
		bzero(Buffer, BUFFER_SIZE);

		if (recv(Socket, Buffer, BUFFER_SIZE, 0) > 0)
		{
			memcpy(Group, Buffer, GROUP_NO_SIZE);
			int GroupNo = atoi(Group);

			if (!strncmp(Buffer + GROUP_NO_SIZE, "Socket Exit:", 12))	//�׽��ֱ�ͣ��
			{
				int Socket = atoi(Buffer + GROUP_NO_SIZE + 12);
				SocketsBox[GroupNo][Socket] = false;

				/*
					֪ͨUI��GroupNo���Socket�׽��ֱ�ͣ�ã���Ӧ�û��˳�����
				*/
			}
			else
			{
				for (int i = 0; i < MaxSocket; i++)	//�������ݰ�ת�������ڷ���������ĸ���Ա
				{
					if (Socket != i && SocketsBox[GroupNo][i])
					{
						send(i, Buffer, strlen(Buffer), 0);
					}
				}

				bzero(Buffer, BUFFER_SIZE);
			}
		}
	}
	pthread_exit(NULL);
}

void Server::ServerOnline()
{
	/*ʹ�׽��ֽ������״̬*/
	listen(ServerSocket, 2 * USER_SUM_SIZE);

	/*
		֪ͨUI�������������
	*/

	while (1)
	{
		struct sockaddr_in ClientAddr;
		socklen_t ClientAddrSize = sizeof(ClientAddr);
		int ClientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddr, &ClientAddrSize);

		SocketsBox[ClientSocket] = true;

		/*
			֪ͨUI�׽���ClientSocket��Ӧ�û���������
		*/

		/*Ϊ���û������߳�*/
		pthread_t ClientThread;
		pthread_create(&ClientThread, NULL, TransBuffer, (void *) &ClientSocket);
	}
}