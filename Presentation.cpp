#include "Presentation.h"
#include "Transport.h"

Presentation::Presentation()
{
    down = new Transport();
    down->setUp(this);
}

void Presentation::configure(config settings)
{
    encoding = settings.encoding;
    
    Layer::configure(settings);
}

void Presentation::execute(Message* message, bool sending=true)
{
    if (sending)
    {
        message->setEncoding(encoding);
        down->execute(message, sending);
    }
    else
    {
        if (message->getEncoding() == encoding)
        {
            std::cout<< "Message at Presentation layer on computer: " << computerName <<std::endl;
            up->execute(message, false);
        }
        else
        {
            std::cout<< "Encoding type mismatch on computer: " << computerName << " Expected: " << encoding <<std::endl;
            message->PrintMessage();
        }
    }
}

// ;)