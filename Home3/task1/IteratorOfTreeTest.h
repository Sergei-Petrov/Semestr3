#pragma once

#include <QtCore/QtCore>
#include <QtTest/QtTest>
#include "Tree.h"
#include "iostream"

class IteratorOfTreeTest:public QObject
{
    Q_OBJECT

public:
    explicit IteratorOfTreeTest(QObject *parent = 0):QObject(parent){}

private slots:
    void init()
    {
        t = new Tree<int>;
    }

    void cleanup()
    {
        delete t;
    }

    void TestValueIterator()
    {
        t->add(5);
        t->add(7);
        t->add(4);
        Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
        QCOMPARE(*it, 4);
    }

    void TestIteratorNext()
    {
        t->add(0);
        t->add(1);
        t->add(2);
        t->add(3);
        t->add(4);
        t->add(5);
        t->add(6);
        t->add(7);
        t->add(8);
        t->add(8);
        t->add(9);
        stringstream out;
        string str = "0 1 2 3 4 5 6 7 8 8 9 ";
        Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
        for(int i = 0; i < 11; i++)
        {
            out << *it << " ";
            it++;
        }
        QCOMPARE(out.str(), str);
    }

    void TestIteratorPrev()
    {
        t->add(0);
        t->add(1);
        t->add(2);
        t->add(3);
        t->add(4);
        t->add(5);
        t->add(6);
        t->add(7);
        t->add(8);
        t->add(8);
        t->add(9);
        stringstream out;
        string str = "9 8 8 7 6 5 4 3 2 1 0 ";
        Tree<int>::Iterator it = Tree<int>::Iterator(t->last());
        for(int i = 0; i < 11; i++)
        {
            out << *it << " ";
            it--;
        }
        QCOMPARE(out.str(), str);
    }

    void TestIteratorEqually()
    {
        t->add(0);
        t->add(1);
        Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
        Tree<int>::Iterator it2 = Tree<int>::Iterator(t->first());
        QVERIFY(it == it2);
    }

    void TestIteratorNotEqually()
    {
        t->add(0);
        t->add(1);
        Tree<int>::Iterator it = Tree<int>::Iterator(t->first());
        Tree<int>::Iterator it2 = Tree<int>::Iterator(t->last());
        QVERIFY(it != it2);
    }
private:
    Tree<int> *t;
};
