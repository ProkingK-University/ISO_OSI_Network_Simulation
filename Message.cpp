#include "Message.h"

Message::Message(std::string Messagedata) : data(Messagedata)
{
    contentLength = Messagedata.length();

    Encoding = "";
    Destination = "";
    Origin = "";
}

Message::Message(Message* msg)
{
    data = msg->data;
    contentLength = msg->contentLength;

    Encoding = "";
    Destination = "";
    Origin = "";
}

std::string Message::getdata() {return data;}

std::string Message::getDestination()
{
    if (Destination == "")
    {
        return "ERROR: INCOMPLETE ADDRESS";
    }
    else
    {
        std::string s = "";
        std::string strDiv = "";
        std::stringstream ss;
        std::stringstream sss(Destination);

        getline(sss, strDiv, ':');
        ss << strDiv;

        for (int i = 0; i < 4; i++)
        {
            getline(ss, s, '.');

            if (s == "")
            {
                return "ERROR: INCOMPLETE ADDRESS";
            }
            else
            {
                for (long unsigned int i = 0; i < s.length(); i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return "ERROR: INCOMPLETE ADDRESS";
                    }
                }
                
                try
                {
                    if (stoi(s) < 0 || stoi(s) > 255)
                    {
                        return "ERROR: INCOMPLETE ADDRESS";
                    }
                }
                catch(...) {return "ERROR: INCOMPLETE ADDRESS";}
            }
        }

        getline(sss, strDiv, ':');

        if (strDiv == "")
        {
            return "ERROR: INCOMPLETE ADDRESS";
        }
        else
        {
            for (long unsigned int i = 0; i < strDiv.length(); i++)
            {
                if (!isdigit(strDiv[i]))
                {
                    return "ERROR: INCOMPLETE ADDRESS";
                }
            }
            
            try
            {
                if (stoi(strDiv) < 0 || stoi(strDiv) > 65535)
                {
                    return "ERROR: INCOMPLETE ADDRESS";
                }
            }
            catch(...) {return "ERROR: INCOMPLETE ADDRESS";}
        }

        return Destination;
    }
}

std::string Message::getOrigin()
{
    if (Origin == "")
    {
        return "ERROR: INCOMPLETE ADDRESS";
    }
    else
    {
        std::string s = "";
        std::string strDiv = "";
        std::stringstream ss;
        std::stringstream sss(Origin);

        getline(sss, strDiv, ':');
        ss << strDiv;

        for (int i = 0; i < 4; i++)
        {
            getline(ss, s, '.');

            if (s == "")
            {
                return "ERROR: INCOMPLETE ADDRESS";
            }
            else
            {
                for (long unsigned int i = 0; i < s.length(); i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return "ERROR: INCOMPLETE ADDRESS";
                    }
                }
                
                try
                {
                    if (stoi(s) < 0 || stoi(s) > 255)
                    {
                        return "ERROR: INCOMPLETE ADDRESS";
                    }
                }
                catch(...) {return "ERROR: INCOMPLETE ADDRESS";}
            }
        }

        getline(sss, strDiv, ':');

        if (strDiv == "")
        {
            return "ERROR: INCOMPLETE ADDRESS";
        }
        else
        {
            for (long unsigned int i = 0; i < strDiv.length(); i++)
            {
                if (!isdigit(strDiv[i]))
                {
                    return "ERROR: INCOMPLETE ADDRESS";
                }
            }
            
            try
            {
                if (stoi(strDiv) < 0 || stoi(strDiv) > 65535)
                {
                    return "ERROR: INCOMPLETE ADDRESS";
                }
            }
            catch(...) {return "ERROR: INCOMPLETE ADDRESS";}
        }

        return Origin;
    }
}

std::string Message::getEncoding(){return Encoding;}

std::string Message::getDestinationIP()
{
    std::string s = "";
    std::string str = "";
    std::stringstream sss;
    std::stringstream ss(Destination);

    getline(ss, s, ':');
    sss << s;

    for (int i = 0; i < 4; i++)
    {
        getline(sss, str, '.');

        for (long unsigned int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
            {
                return "ERROR: IPV4 NOT SET";
            }
        }

        try
        {
            if (stoi(str) < 0 || stoi(str) > 255)
            {
               return "ERROR: IPV4 NOT SET";
            }
        }
        catch(...) {return "ERROR: IPV4 NOT SET";}
    }
    
   return s;
}

std::string Message::getDestinationPort()
{ 
    std::string s = "";
    std::stringstream ss(Destination);

    getline(ss, s, ':');
    getline(ss, s, ':');

    for (long unsigned int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {
            return "ERROR: PORT NOT SET";
        }
    }

    try
    {
        if (stoi(s) < 0 || stoi(s) > 65535)
        {
            return "ERROR: PORT NOT SET";
        }
    }
    catch(...) {return "ERROR: PORT NOT SET";}

    return s;
}

std::string Message::getOriginIP()
{
    std::string s = "";
    std::string str = "";
    std::stringstream sss;
    std::stringstream ss(Origin);

    getline(ss, s, ':');
    sss << s;

    for (int i = 0; i < 4; i++)
    {
        getline(sss, str, '.');

        for (long unsigned int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
            {
                return "ERROR: IPV4 NOT SET";
            }
        }

        try
        {
            if (stoi(str) < 0 || stoi(str) > 255)
            {
               return "ERROR: IPV4 NOT SET";
            }
        }
        catch(...) {return "ERROR: IPV4 NOT SET";}
    }

    return s;
}

std::string Message::getOriginPort()
{
    std::string s = "";
    std::stringstream ss(Origin);

    getline(ss, s, ':');
    getline(ss, s, ':');

    for (long unsigned int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {
            return "ERROR: PORT NOT SET";
        }
    }

    try
    {
        if (stoi(s) < 0 || stoi(s) > 65535)
        {
            return "ERROR: PORT NOT SET";
        }
    }
    catch(...) {return "ERROR: PORT NOT SET";}

    return s;
}

bool Message::setDestinationIP(std::string DestIP)
{
    if (getDestinationIP() != "ERROR: IPV4 NOT SET")
    {
        return false;
    }
    else
    {
        std::string s = "";
        std::stringstream ss(DestIP);

        for (int i = 0; i < 4; i++)
        {
            getline(ss, s, '.');

            for (long unsigned int i = 0; i < s.length(); i++)
            {
                if (!isdigit(s[i]))
                {
                    return false;
                }
            }

            try
            {
                if (stoi(s) < 0 || stoi(s) > 255)
                {
                    return false;
                }
            }
            catch(...) {return false;}
        }

        if (Destination == "")
        {
            Destination = DestIP + ":";
        }
        else
        {
            std::string port = Destination;

            Destination = DestIP + ":" + port;
        }

        return true;
    }
}

bool Message::setDestinationPort(std::string DestPort)
{
    if (getDestinationPort() != "ERROR: PORT NOT SET")
    {
        return false;
    }
    else
    {
        for (long unsigned int i = 0; i < DestPort.length(); i++)
        {
            if (!isdigit(DestPort[i]))
            {
                return false;
            }
        }
        
        try
        {
            if (stoi(DestPort) < 0 || stoi(DestPort) > 65535)
            {
                return false;
            }
        }
        catch(...) {return false;}
        
        if (Destination == "")
        {
            Destination = DestPort;
        }
        else
        {
            std::string ip = Destination;

            Destination = ip + DestPort;
        }

        return true;
    }
}

bool Message::setOriginIP(std::string OriginIP)
{
    if (getOriginIP() != "ERROR: IPV4 NOT SET")
    {
        return false;
    }
    else
    {
        std::string s = "";
        std::stringstream ss(OriginIP);

        for (int i = 0; i < 4; i++)
        {
            getline(ss, s, '.');

            for (long unsigned int i = 0; i < s.length(); i++)
            {
                if (!isdigit(s[i]))
                {
                    return false;
                }
            }

            try
            {
                if (stoi(s) < 0 || stoi(s) > 255)
                {
                    return false;
                }
            }
            catch(...) {return false;}
        }

        if (Origin == "")
        {
            Origin = OriginIP + ":";
        }
        else
        {
            std::string port = Origin;

            Origin = OriginIP + ":" + port;
        }

        return true;
    }
}

bool Message::setOriginPort(std::string OriginPort)
{
    if (getOriginPort() != "ERROR: PORT NOT SET")
    {
        return false;
    }
    else
    {
        for (long unsigned int i = 0; i < OriginPort.length(); i++)
        {
            if (!isdigit(OriginPort[i]))
            {
                return false;
            }
        }
        
        try
        {
            if (stoi(OriginPort) < 0 || stoi(OriginPort) > 65535)
            {
                return false;
            }
        }
        catch(...) {return false;}

        if (Origin == "")
        {
            Origin = OriginPort;
        }
        else
        {
            std::string ip = Origin;

            Origin = ip + OriginPort;
        }

        return true;
    }
}

void Message::setEncoding(std::string Encoding)
{
    this->Encoding = Encoding;
}

void Message::PrintMessage()
{
    std::cout<< "Data: " << data <<std::endl;
    std::cout<< "Destination: " << getDestination() <<std::endl;
    std::cout<< "Destination IPV4: " << getDestinationIP() <<std::endl;
    std::cout<< "Destination Port: " << getDestinationPort() <<std::endl;
    std::cout<< "Origin: " << getOrigin() <<std::endl;
    std::cout<< "Origin IPV4: " << getOriginIP() <<std::endl;
    std::cout<< "Origin Port: " << getOriginPort() <<std::endl;
    std::cout<< "Encoding: " << getEncoding() <<std::endl;
}

Message::~Message()
{
    std::cout<< "Deleted message containting: " << data <<std::endl;
}

int Message::getContentLength(){return contentLength;}

void Message::setContentLength(int contentLength)
{
    this->contentLength = contentLength;
}

// ;)