#include<iostream>
#include "priority_queue.h"
using namespace std;

int main()
{
    priorityQueue a;
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(7);
    a.insert(9);

    cout << a.parentData_index(1).first << endl;

    a.checkChild(0);

    cout << a.isEmpty() << endl;
    cout << a.getSize() << endl;

    cout << a.getMin() << endl;
}