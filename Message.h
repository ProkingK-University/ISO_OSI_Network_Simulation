#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

class Message
{
private:
    std::string data;
    std::string Origin;
    std::string Encoding;
    std::string Destination;

    int contentLength;
public:
    Message(std::string Messagedata);
    Message(Message* msg);

    std::string getdata();
    std::string getDestination();
    std::string getOrigin();
    std::string getEncoding();
    std::string getDestinationIP();
    std::string getDestinationPort();
    std::string getOriginIP();
    std::string getOriginPort();

    bool setDestinationIP(std::string DestIP);
    bool setDestinationPort(std::string DestPort);
    bool setOriginIP(std::string OriginIP);
    bool setOriginPort(std::string OriginPort);

    void setEncoding(std::string Encoding);
    void PrintMessage();

    int getContentLength();
    void setContentLength(int contentLength);

    ~Message();
};

#endif