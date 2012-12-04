#include "Computer.h"

Computer::Computer(OS *o, bool status) : os(o), isInfected(status)
{}

void Computer::virusAttack(int test)
{
    int risk = 0;
    if (test = -1)
        risk = rand() % MAX_CHANCE;
    else
        risk = test;
    if (risk <= os->getChance())
        isInfected = true;
}

bool Computer::checkForInfection()
{
    return isInfected;
}
