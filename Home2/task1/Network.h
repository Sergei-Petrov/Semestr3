#pragma once

#include "MacOS.h"
#include "Linux.h"
#include "Windows.h"
#include "Computer.h"
#include "Sleeper.h"
#include "sstream"
#include <string>
#include <QList>

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
    Network(Computer **comp, int *net[], bool isTest);

    /// method that gives network status
    string printLocalSystemStatus();

    /// one step of work
    string oneStep();

    /// network work
    string work();

    /// check for infection of the full system
    bool checkNetworkToBeInfected();

private:
    /// array of computers in a local network consisting
    Computer **Computers;
    /// computer connection (the adjacency matrix)
    int *net_m[numberOfComputers];
    bool test;
    QList<int> list;
};
