#ifndef LAYER_H
#define LAYER_H

#include "Message.h"

struct config
{
public:
    std::string ip;
    std::string port;
    std::string DestIP;
    std::string encoding;
    std::string DestPort;
    std::string computerName;
};


class Layer
{
protected:
    Layer* up;
    Layer* down;

    std::string computerName;
public:
    Layer();

    Layer* getDown();

    void setUp(Layer* up);
    virtual void link(Layer* linkStack);
    virtual void configure(config settings);

    virtual void execute(Message* message, bool) = 0;

    virtual ~Layer();
};

#endif