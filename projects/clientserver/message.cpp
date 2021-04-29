#include<message>
Message::Message(int header, long int body) : header(header), body(body) {}

string Message::getBuffer()
{
    char buff[10];
    buff[0] = to_string(header).c_str()[0];
    int i = 1;
    for(auto c : to_string(body))
    {
        buff[i++] = (char)c;
        
    }
    buff[i] = 0;
    
    return buff;
}