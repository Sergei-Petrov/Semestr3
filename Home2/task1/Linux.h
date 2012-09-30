#pragma once

#include "OS.h"

class Linux : public OS
{
public:
    Linux()
    {
        chanceOfInfection = 2;
    }
};
