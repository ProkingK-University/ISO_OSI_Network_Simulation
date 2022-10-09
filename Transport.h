#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Layer.h"

class Transport : public Layer
{
private:
    std::string port;
    std::string DestPort;
public:
    Transport();

    void configure(config settings);
    void execute(Message* messeage, bool);
};
#endif