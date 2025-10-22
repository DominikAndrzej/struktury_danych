#include <iostream>

#include "DoubleLinkedList/DoubleLinkedList.h"

using namespace std;

int main() {



    DoubleLinkedList<int>* list = new DoubleLinkedList<int>;

    list->addFront(1);
    list->addFront(2);
    list->addFront(3);

    list->toString();

    list->rmvFront();
    list->rmvBack();

    list->toString();

    list->addBack(4);
    list->addBack(5);
    list->addBack(6);

    list->toString();

    cout << list->getElementByIndex(2) << endl;

    return 0;
}