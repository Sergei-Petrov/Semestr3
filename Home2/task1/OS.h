#pragma once

/// Interface for operating system
class OS
{
public:
    /// method that gives a chance of infection
    int getChance()
    {
        return chanceOfInfection;
    }

protected:
    /// chance of infection
    int chanceOfInfection;
};
