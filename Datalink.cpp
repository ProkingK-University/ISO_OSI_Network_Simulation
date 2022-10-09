#include "Datalink.h"
#include "Physical.h"

Datalink::Datalink()
{
    down = new Physical();
    down->setUp(this);
}

void Datalink::execute(Message* message, bool sending=true)
{
    if (sending)
    {
        down->execute(message, true);
    }
    else
    {
        std::cout<< "Message at Datalink layer" <<std::endl;
        up->execute(message, false);
    }
}

// ;)