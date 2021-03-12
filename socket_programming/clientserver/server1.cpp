#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close
//#include<pthread.h>
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <exception>
#include <mutex>
using namespace std;

char client_message[2000];
char buffer[1024];
//string buffer;
mutex _mutex; // = PTHREAD_MUTEX_INITIALIZER;

void socketThread(int *arg)
{
    try
    {
        int newSocket = *arg;
        cout << recv(newSocket, client_message, 2000, 0) << endl;
        std::cout << std::this_thread::get_id() << "received this msg from client -- " << client_message << std::endl;
        // Send message to the client socket
        //pthread_mutex_lock(&lock);
        cout << std::this_thread::get_id() << "creating lock" << endl;
        lock_guard<mutex> lck(_mutex);
        char *message = (char *)malloc(sizeof(client_message) + 50);
        strcpy(message, "Hello Client : wassup");
        strcat(message, client_message);
        strcat(message, "\n");
        strcpy(buffer, message);
        free(message);
        //buffer = string("Hello Client :") + client_message;
        //pthread_mutex_unlock(&lock);
        //_mutex.unlock();
        //std::cout << "about to send to client -- " << buffer << std::endl;
        send(newSocket, buffer, strlen(buffer), 0);
        cout << std::this_thread::get_id() << "Message sent " << buffer << endl;
        close(newSocket);
        cout << std::this_thread::get_id() << "Exit socketThread" << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    //pthread_exit(NULL);
}

int main()
{
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
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    //Listen on the socket, with 40 max connection requests queued
    if (listen(serverSocket, 50) == 0)
        cout << "Listening!!!" << endl;
    else
        cout << "Error" << endl;
    //pthread_t tid[60];
    vector<thread> cl;
    int i = 0;
    while (1)
    {
        //Accept call creates a new socket for the incoming connection
        addr_size = sizeof(serverStorage);
        newSocket = accept(serverSocket, (struct sockaddr *)&serverStorage, &addr_size);
        cout << "Socket created " << newSocket << endl;
        //for each client request creates a thread and assign the client request to it to process
        //so the main thread can entertain next request
        //if (pthread_create(&tid[i++], NULL, socketThread, &newSocket) != 0)
        //	printf("Failed to create thread\n");
        cl.push_back(thread(&socketThread, &newSocket));

        //if (i >= 50)
        //{
        //	i = 0;
        //	while (i < 50)
        //	{
        //		pthread_join(tid[i++], NULL);
        //	}
        //	i = 0;
        //}
    }
    for_each(cl.begin(), cl.end(), [](thread &th) {
        cout << "Joining " << th.get_id() << endl;
        th.join();
    });

    return 0;
}