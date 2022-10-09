#ifndef PHYSICAL_H
#define PHYSICAL_H

#include "Layer.h"

class Physical : public Layer
{
private:
    Physical* next;
public:
    Physical();

    Physical* getNext();
    void setNext(Physical* newNext);

    void link(Layer* LinkStack);
    void execute(Message* message, bool sending=true);
    void configure(config settings);
    
    ~Physical();
};

#endif