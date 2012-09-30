#pragma once

#include "OS.h"

class Windows : public OS
{
public:
    Windows()
    {
        chanceOfInfection = 8;
    }
};
