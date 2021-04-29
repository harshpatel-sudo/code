#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
#include<string>
#include<mutex>
#include<time.h>
#include"message.h"
#include"client.h"

using namespace std;
class Socket{
	private:
		char buffer[2000];
		int clientSocket;
		struct sockaddr_in serverAddr;
		socklen_t addr_size;
		socket thisSocket;
	public:
		int clientSocket;
		Socket()
		{
			// Create the socket. 
			thisSocket = socket(PF_INET, SOCK_STREAM, 0);

			//Configure settings of the server address
			// Address family is Internet 
			serverAddr.sin_family = AF_INET;

			//Set port number, using htons function 
			serverAddr.sin_port = htons(7799);

			//Set IP address to localhost
			serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
			memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
		}

		void bind(){
			bind(thisSocket, (struct sockaddr*) & serverAddr, sizeof(serverAddr));
		}
		void connect(){
			connect(thisSocket, (struct sockaddr*) & serverAddr, addr_size);
		}

		int send(char* msg){
			return send(thisSocket, msg.getBuffer().c_str(), 9, 0);
		}
		int recv(){
			return recv(thisSocket, buffer, 9, 0);
		}
		char* getSocketBuffer(){
			return buffer;
		}
		~Socket(){
			close(thisSocket);
		}
};
mutex _mutex;
void Client::cientThread(int arg)
{
	Socket clientSocket;
	clientSocket.connect();
	//
	Message msg(0, 0);//string("ConnReq");

	if (clientSocket.send(msg.getBuffer().c_str()) < 0)
	{
		printf("Send failed\n");
	}
	else
	{
		cout << "sent : " << msg.getBuffer() << endl;
	}
	//Read the message from the server into the buffer
	if (clientSocket.recv() < 0)
	{
		cout << "rcv failed buffer was : " << buffer << endl;
	}
	else
	{
		if(clientSocket.getBuffer[0] != '2')
		{
			cout << "rcvd wrong msg closing conn msg : " << buffer << endl;			
		}
		else
		{
			for(int i =0; i<100; i++)
			{
				long int ns;
				struct timespec spec;

				clock_gettime(CLOCK_REALTIME, &spec);
				ns = spec.tv_nsec;
				
				Message seqRes(3, ns);
				clientSocket.send(seqRes.getBuffer().c_str());
				
				sleep(.1);
			}
			clientSocket.send(Message(1,0).getBuffer().c_str());
		}
	}
	close(clientSocket);
}