#ifndef MESSAGE_H
#define MESSAGE_H

struct Message
{
	int header;
	long int body;
	
	Message(int header, long int body);
	string getBuffer();	
};
#endif