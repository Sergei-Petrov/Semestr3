#pragma once

class OS
{
public:
    int getChance()
    {
        return chanceOfInfection;
    }

protected:
    int chanceOfInfection;
};
