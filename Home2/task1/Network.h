#pragma once

#include "MacOS.h"
#include "Linux.h"
#include "Windows.h"
#include "Computer.h"
#include "Sleeper.h"
#include "sstream"
#include "iostream"
#include <string>

const int numberOfComputers = 5;

using namespace std;

class Network
{
public:
    Network(Computer **comp, int *net[])
    {
        Computers = comp;
        for (int i = 0; i < numberOfComputers; ++i)
            net_m[i] = net[i];
    }

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

    string work()
    {
        stringstream out;
        if (!check())
            do
            {
                cout << printLocalSystemStatus();
                for (int i = 0; i < numberOfComputers; ++i)
                    for (int j = 0; j < numberOfComputers; ++j)
                        if (net_m[i][j] == 1)
                            if (Computers[i]->getStatus())
                                Computers[j]->virusAttack();
                Sleeper::msleep(2000);
                cout << endl;
            } while (!check());
        cout << printLocalSystemStatus();
        return out.str();
    }

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
    Computer **Computers;
    int *net_m[numberOfComputers];
};
