#include "IteratorOfTreeTest.h"
#include "TreeTest.h"
#include "iostream"

int main()
{
    TreeTest test;
    QTest::qExec(&test);
    cout << endl;
    IteratorOfTreeTest test2;
    QTest::qExec(&test2);
    return 0;
}
