#include "Network.h"

Network::Network(Computer **comp, int *net[], bool isTest)
{
    if (!isTest)
        srand(time(NULL));
    else
    {
        list.push_back(1);
        list.push_back(7);
        list.push_back(4);
        list.push_back(0);
        list.push_back(9);
        list.push_back(4);
        list.push_back(8);
        list.push_back(8);
        list.push_back(2);
        list.push_back(4);
        list.push_back(5);
        list.push_back(5);
    }
    Computers = comp;
    for (int i = 0; i < numberOfComputers; ++i)
        net_m[i] = net[i];
    test = isTest;
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
                if (test)
                {
                    Computers[j]->virusAttack(list[0]);
                    list.pop_front();
                }
                else
                    Computers[j]->virusAttack(-1);
    Sleeper::msleep(700);
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
