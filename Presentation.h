#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "Layer.h"

class Presentation : public Layer
{
private:
    std::string encoding;
public:
    Presentation();

    void configure(config settings);
    void execute(Message* message, bool sending=true);
};
#endif