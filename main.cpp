#include <iostream>

#include "DoubleLinkedList/DoubleLinkedList.h"

using namespace std;

int main() {

    DoubleLinkedList<int>* list = new DoubleLinkedList<int>;

    list->addFront(2);
    list->addFront(5);
    list->addFront(1);

    list->toString();

    list->rmvFront();
    list->rmvBack();
    list->rmvBack();
    list->rmvBack();
    list->rmvFront();

    list->toString();
    return 0;
}