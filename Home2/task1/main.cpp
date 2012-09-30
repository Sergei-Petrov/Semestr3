#include "NetworkTest.h"

int main()
{
    NetworkTest test;
    QTest::qExec(&test);
    return 0;
}
