#pragma once

#include "OS.h"

class MacOS : public OS
{
public:
    MacOS()
    {
        chanceOfInfection = 4;
    }
};
