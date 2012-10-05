#pragma once

#include "QThread"

/// delay
class Sleeper : public QThread
{
public:
    static void msleep(int ms)
    {
        QThread::msleep(ms);
    }
};
