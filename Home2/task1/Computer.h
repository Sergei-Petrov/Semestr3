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
    Computer(OS *o, bool status);

    /// imitation of a virus attack
    void virusAttack();

    /// method that gives the status of infection
    bool checkForInfection();

private:
    /// operating system
    OS *os;
    /// infected or not infected computer
    bool isInfected;
};
