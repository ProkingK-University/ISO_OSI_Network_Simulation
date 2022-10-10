#include "Application.h"
#include "Presentation.h"

Application::Application()
{
    down = new Presentation();

    down->setUp(this);
}

//Passes messages up and down the list
void Application::execute(Message* message, bool sending=true)
{
    if (sending)
    {
        down->execute(message, sending);
    }
    else
    {
        std::cout<< "Computer " << computerName << " Received message: " << message->getdata() <<std::endl;
    }
}

void Application::execute(std::string data, int contentLength)
{
    Message* m = new Message(data);
    
    m->setContentLength(contentLength);
    down->execute(m,true);
}

// ;)