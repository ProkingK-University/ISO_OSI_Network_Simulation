#include "Transport.h"
#include "Network.h"

Transport::Transport()
{
    down = new Network();
    down->setUp(this);
}

void Transport::configure(config settings)
{
    port = settings.port;
    DestPort = settings.DestPort;

    Layer::configure(settings);
}

void Transport::execute(Message* message, bool sending=true)
{
    if (sending)
    {
        if (!message->setOriginPort(port))
        {
            std::cout<< "ERROR OCCURRED WITH ORIGIN PORT" <<std::endl;
            return;
        }

        if (!message->setDestinationPort(DestPort))
        {
            std::cout<< "ERROR OCCURRED WITH DESTINATION PORT" <<std::endl;
            return;
        }

        down->execute(message, true);
    }
    else
    {
        if (message->getDestinationPort() != port)
        {
            std::cout<< "Message sent to wrong port" <<std::endl;
            message->PrintMessage();
        }
        else if (message->getdata().length() != message->getContentLength())
        {
            std::cout<< "Content Length error" <<std::endl;
            message->PrintMessage();
        }
        else if(message->getDestinationPort() == port && message->getdata().length() == message->getContentLength())
        {
            std::cout<< "Message at Transport layer"<<std::endl;
            up->execute(message, false);
        }
    }
}

// ;)