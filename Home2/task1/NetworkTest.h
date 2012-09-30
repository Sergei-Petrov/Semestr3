#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Network.h"
#include "iostream"

class NetworkTest:public QObject
{
    Q_OBJECT

public:
    explicit NetworkTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        Computers[0] = new Computer(new(Linux), 0);
        Computers[1] = new Computer(new(MacOS), 0);
        Computers[2] = new Computer(new(Windows), 0);
        Computers[3] = new Computer(new(Linux), 0);
        Computers[4] = new Computer(new(Windows), 1);
        int array[numberOfComputers][numberOfComputers] =
        {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}
        };
        int *network[numberOfComputers];
        for (int i = 0; i < numberOfComputers; ++i)
            network[i] = array[i];
        obj = new Network(Computers, network);
        Computers2[0] = new Computer(new(Linux), 1);
        Computers2[1] = new Computer(new(MacOS), 1);
        Computers2[2] = new Computer(new(Windows), 1);
        Computers2[3] = new Computer(new(Linux), 1);
        Computers2[4] = new Computer(new(Windows), 1);
        obj2 = new Network(Computers2, network);
    }

    void cleanup()
    {
        for (int i = 0; i < numberOfComputers; i++)
        {
            delete Computers[i];
            delete Computers2[i];
        }
        delete obj;
    }

    void TestCheck()
    {
        QVERIFY(!obj->check() && obj2->check());
    }

    void TestPrintLocalSystemStatus()
    {
        stringstream str;
        str << "Computer #1 isn't infected\n";
        str << "Computer #2 isn't infected\n";
        str << "Computer #3 isn't infected\n";
        str << "Computer #4 isn't infected\n";
        str << "Computer #5 is infected\n";

        QVERIFY(str.str() == obj->printLocalSystemStatus());
    }

    void TestCheckWork()
    {
        cout << "Need wait until work Network" << endl;
        obj->work();
        QVERIFY(obj->check());
    }

private:
    Computer *Computers[numberOfComputers];
    Computer *Computers2[numberOfComputers];
    Network *obj;
    Network *obj2;
};

QTEST_MAIN(NetworkTest)
