#include "Physical.h"

using namespace std;

Physical::Physical()
{
    next = NULL;
}

void Physical::execute(Message* message, bool sending=true)
{
    if (sending)
    {
        if (!next)
        {
            cout<< "NOT CONNECTED TO A NETWORK" <<endl;
            message->PrintMessage();
        }
        else
        {
            next->execute(message, false);
        }
    }
    else
    {
        cout<< "Message at Physical layer of computer: " << computerName <<endl;
        up->execute(message, false);
    }
}

Physical::~Physical()
{
    next = NULL;
}

void Physical::link(Layer* LinkStack)
{
    while (LinkStack)
    {
        LinkStack = LinkStack->getDown();
    }

    next = (Physical*) LinkStack;
}

Physical* Physical::getNext() {return next;}

void Physical::setNext(Physical* newNext)
{
    next = newNext;
}

void Physical::configure(config settings)
{
    computerName = settings.computerName;
}

// ;)