#pragma once

#include "cstdlib"
#include "time.h"
#include "OS.h"

const int MAX_CHANCE = 10;

/// computer simulation
class Computer
{
public:
    /**
      * constructor
      *
      * param o - computer operating system,
      * param status - infected or not infected computer
      */
    Computer(OS *o, bool status): os(o), isInfected(status)
    {
        srand(time(NULL));
    }

    /// imitation of a virus attack
    void virusAttack()
    {     
        int risk = rand() % MAX_CHANCE;
        if (risk <= os->getChance())
            isInfected = true;
    }

    /// method that gives the status of infection
    bool getStatus()
    {
        return isInfected;
    }

private:
    /// operating system
    OS *os;
    /// infected or not infected computer
    bool isInfected;

};
