#ifndef DATALINK_H
#define DATALINK_H

#include "Layer.h"

class Datalink : public Layer
{
public:
    Datalink();

    void execute(Message* messege, bool sending=true);
};

#endif
