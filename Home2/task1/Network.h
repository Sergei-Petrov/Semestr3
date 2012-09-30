#pragma once

#include "MacOS.h"
#include "Linux.h"
#include "Windows.h"
#include "Computer.h"
#include "Sleeper.h"
#include "sstream"
#include <string>

const int numberOfComputers = 5;

using namespace std;

/// imitation of the local system
class Network
{
public:
    /**
      * constructor
      *
      * param comp - array of computers in a local network consisting,
      * param net - computer connection (the adjacency matrix)
      */
    Network(Computer **comp, int *net[])
    {
        Computers = comp;
        for (int i = 0; i < numberOfComputers; ++i)
            net_m[i] = net[i];
    }

    /// method that gives network status
    string printLocalSystemStatus()
    {
        stringstream out;
        for (int i = 0; i < numberOfComputers; ++i)
        {
            if (Computers[i]->getStatus())
                out << "Computer #" << i + 1 << " is infected" << endl;
            else
                out << "Computer #" << i + 1 << " isn't infected" << endl;
        }
        return out.str();
    }

    /// network work
    string work()
    {
        stringstream out;
        if (!check())
            do
            {
                out << printLocalSystemStatus();
                for (int i = 0; i < numberOfComputers; ++i)
                    for (int j = 0; j < numberOfComputers; ++j)
                        if (net_m[i][j] == 1)
                            if (Computers[i]->getStatus())
                                Computers[j]->virusAttack();
                Sleeper::msleep(2000);
                out << endl;
            } while (!check());
        out << printLocalSystemStatus();
        return out.str();
    }

    ///
    bool check()
    {
        int k = 0;
        for (int i = 0; i < numberOfComputers; i++)
        {
            if (Computers[i]->getStatus())
                k++;
        }
        return k > numberOfComputers - 1;
    }

private:
    /// array of computers in a local network consisting
    Computer **Computers;
    /// computer connection (the adjacency matrix)
    int *net_m[numberOfComputers];
};
