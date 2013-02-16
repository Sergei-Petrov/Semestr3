#include "Computer.h"

Computer::Computer(OS *o, bool status) : os(o), isInfected(status)
{}

void Computer::virusAttack(int risk)
{
    if (risk <= os->getChance())
        isInfected = true;
}

bool Computer::checkForInfection()
{
    return isInfected;
}
