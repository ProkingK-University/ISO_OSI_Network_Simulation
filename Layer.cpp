//Parent class

#include "Layer.h"

Layer::Layer()
{
    computerName = "";
    up = NULL;
    down = NULL;
}

Layer* Layer::getDown() {return down;}

void Layer::setUp(Layer* up)
{
    this->up = up;
}

void Layer::link(Layer* linkStack)
{
    down->link(linkStack);
}

void Layer::configure(config settings)
{
    computerName = settings.computerName;
    
    down->configure(settings);
}

Layer::~Layer()
{
    if (down)
    {
        delete down;
        down = NULL;
    }
}

// ;)