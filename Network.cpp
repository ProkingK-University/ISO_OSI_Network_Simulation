#include "Network.h"
#include "Datalink.h"

Network::Network()
{
    down = new Datalink();
    down->setUp(this);
}

void Network::configure(config settings)
{
    ip = settings.ip;
    DestIP = settings.DestIP;

    Layer::configure(settings);
}

void Network::execute(Message* message, bool sending=true)
{
    if (sending)
    {
        if (!message->setOriginIP(ip))
        {
            std::cout<< "ERROR OCCURRED WITH ORIGIN IP" <<std::endl;
            return;
        }

        if (!message->setDestinationIP(DestIP))
        {
            std::cout<< "ERROR OCCURRED WITH DESTINATION IP" <<std::endl;
            return;
        }

        down->execute(message, true);
    }
    else
    {
        if (message->getDestinationIP() == DestIP)
        {
            std::cout<< "Message at Network layer" <<std::endl;
            up->execute(message, false);
        }
        else if (message->getOriginIP() == ip)
        {
            std::cout<< "Message has been returned to sender without finding the destination" <<std::endl;
            message->PrintMessage();
        }
        else
        {
            std::cout<< "Message at Network layer" <<std::endl;
            down->execute(message, true);
        }
    }
}

// ;)