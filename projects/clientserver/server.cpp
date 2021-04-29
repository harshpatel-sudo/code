#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <iostream>
#include <thread>
#include<vector>
#include <algorithm>
#include<exception>
#include<mutex>
#include<map>
#include<set>
#include"Message"
using namespace std;

mutex _mutex1;
map<int, long> clientsData;
int track = 0;


int createClient()
{	//lock_guard<mutex> lck(_mutex);
	
	int clientId = clientsData.size() + 1;
	clientsData.insert(make_pair(clientId, 0));
	//cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	//cout << "creating key = " << clientId << " & vlaue = 0" << endl;
	//cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	return clientId;
}

void updateClient(int id, long seqNo)
{	//lock_guard<mutex> lck(_mutex);
	
	if(clientsData.find(id) != clientsData.end())
		clientsData[id] = seqNo;
	//cout << "*************************************************************" << endl;
	//for(auto i : clientsData)
	//{
	//	cout << i.first << "-" << i.second << endl;
	//}
	//cout << "*************************************************************"<< endl;
	
}

void socketThread(int arg)
{
	char client_message[9];
	char client_ns[9];
	char buffer[9];
	int newSocket = arg;
	
	recv(newSocket, client_message, 9, 0);
	std::cout << "received this msg from client -- " << client_message << std::endl;
	
	if(client_message[0] != '0')
	{
		
	}
	else
	{
	
	_mutex1.lock();
	int clientId = createClient();
	_mutex1.unlock();
	Message seqReq(2, 0);
	std::cout << "about to send to client -- " << seqReq.getBuffer() << std::endl;
	
	send(newSocket, seqReq.getBuffer().c_str(), 9, 0);
	
	while(1)
	{
		recv(newSocket, client_ns, 9, 0);
		
		if(client_ns[0] == '1')
		{
			_mutex1.lock();
			track++;
			_mutex1.unlock();
			break;
		}
		else
		{
			_mutex1.lock();
			updateClient(clientId, stol(string(client_ns).substr(1)));
			_mutex1.unlock();
		}
	}
	
	
	
	printf("Exit socketThread \n");
	}
	close(newSocket);
}

int main(int argc, char** argv) 
{
	if(argc != 3)
	{
		cout << "Please Provide valid input" << endl;
	}
	else
	{
	int noOfClients = *((int*)argv[1]);
	int noOfThread = *((int*)argv[2]);
	int serverSocket, newSocket;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	//Create the socket. 
	serverSocket = socket(PF_INET, SOCK_STREAM, 0);

	// Configure settings of the server address struct
	// Address family = Internet 
	serverAddr.sin_family = AF_INET;

	//Set port number, using htons function to use proper byte order 
	serverAddr.sin_port = htons(7799);

	//Set IP address to localhost 
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");


	//Set all bits of the padding field to 0 
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	//Bind the address struct to the socket 
	bind(serverSocket, (struct sockaddr*) & serverAddr, sizeof(serverAddr));

	//Listen on the socket, with 40 max connection requests queued 
	if (listen(serverSocket, 50) == 0)
		printf("Listening!!!\n");
	else
		printf("Error\n");
	vector<thread> cl; 
	int i = 0;
	
	vector<int> connectedClients;
	while (1)
	{
		
		//Accept call creates a new socket for the incoming connection
		addr_size = sizeof serverStorage;
		newSocket = accept(serverSocket, (struct sockaddr*) & serverStorage, &addr_size);
		i++;
		connectedClients.push_back(newSocket);
		cl.push_back(thread(&socketThread , newSocket));
		
	}
	for_each(cl.begin(), cl.end(), [](thread &th) {
        //cout << "Joining " << th.get_id() << endl;
        th.join();
    });
	}
	sort(clientsData);
	
	return 0;
}