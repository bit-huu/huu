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
	bool SocketsBox[GROUP_SUM_SIZE][USER_SUM_SIZE];	//标志各聊天组内是否有某个套接字
	struct sockaddr_in ServerAddr;
	int ServerSocket;
	int MaxSocket;

	Server();
	~Server();

	void TransBuffer(void* _Socket);	//信息中转
	void ServerOnline();	//运行服务端

private:

};

Server::Server(char ServerIP[])
{
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	ServerAddr.sin_family = AF_INET;	//使用IPV4通信
	ServerAddr.sin_addr.s_addr = inet_addr(ServerIP);
	ServerAddr.sin_port = htons(8080);	//端口

	/*连接地址与套接字*/
	bind(ServerSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
}

Server::~Server()
{
	/*关闭套接字*/
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

			if (!strncmp(Buffer + GROUP_NO_SIZE, "Socket Exit:", 12))	//套接字被停用
			{
				int Socket = atoi(Buffer + GROUP_NO_SIZE + 12);
				SocketsBox[GroupNo][Socket] = false;

				/*
					通知UI第GroupNo组的Socket套接字被停用，对应用户退出聊天
				*/
			}
			else
			{
				for (int i = 0; i < MaxSocket; i++)	//将该数据包转发给组内发送者以外的各成员
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
	/*使套接字进入监听状态*/
	listen(ServerSocket, 2 * USER_SUM_SIZE);

	/*
		通知UI服务器部署完毕
	*/

	while (1)
	{
		struct sockaddr_in ClientAddr;
		socklen_t ClientAddrSize = sizeof(ClientAddr);
		int ClientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddr, &ClientAddrSize);

		SocketsBox[ClientSocket] = true;

		/*
			通知UI套接字ClientSocket对应用户加入聊天
		*/

		/*为新用户创建线程*/
		pthread_t ClientThread;
		pthread_create(&ClientThread, NULL, TransBuffer, (void *) &ClientSocket);
	}
}