#pragma once

#include "cstdlib"
#include "time.h"
#include "OS.h"

const int MAX_CHANCE = 10;

class Computer
{
public:
    Computer(OS *o, bool status): os(o), isInfected(status)
    {
        srand(time(NULL));
    }

    void virusAttack()
    {     
        int risk = rand() % MAX_CHANCE;
        if (risk <= os->getChance())
            isInfected = true;
    }

    bool getStatus()
    {
        return isInfected;
    }

private:
    OS *os;
    bool isInfected;

};
