#ifndef NETWORK_H
#define NETWORK_H

#include "Layer.h"

class Network : public Layer
{
private:
    std::string ip;
    std::string DestIP;
public:
    Network();

    void configure(config settings);
    void execute(Message* message, bool sending=true);
};
#endif