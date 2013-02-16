#include "Network.h"

Network::Network(Computer **comp, int *net[], Random *r)
{
    Computers = comp;
    for (int i = 0; i < numberOfComputers; ++i)
        net_m[i] = net[i];
    random = r;
}

string Network::printLocalSystemStatus()
{
    stringstream out;
    for (int i = 0; i < numberOfComputers; ++i)
    {
        if (Computers[i]->checkForInfection())
            out << "Computer #" << i + 1 << " is infected" << endl;
        else
            out << "Computer #" << i + 1 << " isn't infected" << endl;
    }
    return out.str();
}

string Network::oneStep()
{
    stringstream out;
    out << printLocalSystemStatus();
    for (int i = 0; i < numberOfComputers; ++i)
        for (int j = 0; j < numberOfComputers; ++j)
            if (net_m[i][j] == 1 && Computers[i]->checkForInfection())
                Computers[j]->virusAttack(random->ran());
    Sleeper::msleep(500);
    out << endl;
    return out.str();
}

string Network::work()
{
    stringstream out;
    if (!checkNetworkToBeInfected())
        do
            out << oneStep();
        while (!checkNetworkToBeInfected());
    out << printLocalSystemStatus();
    return out.str();
}

bool Network::checkNetworkToBeInfected()
{
    int k = 0;
    for (int i = 0; i < numberOfComputers; i++)
        if (Computers[i]->checkForInfection())
            k++;
    return k > numberOfComputers - 1;
}
