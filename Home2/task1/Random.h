#pragma once
#include <cstdlib>
#include <ctime>
#include <QList>

class Random
{
public:
    virtual int ran() = 0;
};

class RealRandom : public Random
{
public:
    int ran()
    {
        srand(time(0));
        return rand() % 10;
    }
};

class TestRandom : public Random
{
public:
    TestRandom()
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

    int ran()
    {
        if (list.empty())
            return 0;
        int rez = list[0];
        list.pop_front();
        return rez;
    }

private:
    QList<int> list;
};
