//
// Created by Dominik on 15.10.2025.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"

template<typename T>
class DoubleLinkedList {
    Node<T> * head;
    Node<T> * tail;
    int size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void addFront(T value);
    void addBack(T value);
    void rmvFront(); // remove front node
    void rmvBack(); // remove back node
    void toString(); // prints some data about list to console
    Node<T>* getElementByIndex(int index); // returns pointer to an element searched by index
    void delElementOnIndex(int index); // deletes element on given index
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    head->prev = tail;
    tail->next = head;
    size = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {}


template<typename T>
void DoubleLinkedList<T>::addFront(T value) {

    Node<T>* newNode = new Node<T>(value);

    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

template<typename T>
void DoubleLinkedList<T>::addBack(T value) {

    Node<T>* newNode = new Node<T>(value);

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }

    size++;
}

/**
 * remove node from the back of the list
 */
template<typename T>
void DoubleLinkedList<T>::rmvBack() {

    // removing is possible only if the back node (tail) exists
    if (tail) {
        if (tail == head) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            size = 0;
        } else {
            Node<T>* tempNode = tail;

            tail = tempNode->prev;
            tail->next = nullptr;
            delete tempNode;

            size--;
        }

    }
}

template<typename T>
void DoubleLinkedList<T>::toString() {
    printf("Size: %d\nElements: \n", size);

    if (!head) {
        printf("There aren't any elements");
    } else {
        Node<T>* currentNode = head;

        while (currentNode != tail) {
            std::cout << currentNode->prev << " <--- "
                << currentNode->value << " : " << currentNode << " ---> "
                << currentNode->next << std::endl;
            currentNode = currentNode->next;
        }
        std::cout << currentNode->prev << " <--- "
                << currentNode->value << " : " << currentNode << " ---> "
                << currentNode->next << std::endl;
    }
}

/**
 *
 * @param index starts with 0
 * @return pointer to element with given id, if element doesn't exists return nullptr
 */
template<typename T>
Node<T>* DoubleLinkedList<T>::getElementByIndex(int index) {
    if (head && tail) { // if head and tail aren't nullpointers
        if (index+1 > size || index < 0) {
            return nullptr;
        }

        Node<T>* currentNode = head;
        int counter = 0;

        while (counter != index) {
            currentNode = currentNode->next;
            counter++;
        }

        return currentNode;
    }

    return nullptr; // if head or tail are null pointers then return nullptr
}

template<typename T>
void DoubleLinkedList<T>::
delElementOnIndex(int index) {
    if (head && tail) {
        Node<T>* nodeToDel = getElementByIndex(index);

        if (nodeToDel == head) {
            rmvFront();
        } else if (nodeToDel == tail) {
            rmvBack();
        } else {
            Node<T>* prevNode = nodeToDel->prev;
            Node<T>* nextNode = nodeToDel->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            delete nodeToDel;
        }
    }
}

/**
 * remove node from the front of the list
 */
template<typename T>
void DoubleLinkedList<T>::rmvFront() {

    // removing is possible only if the front node (head) exists
    if (head && tail) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
        } else {
            Node<T>* tempNode = head;

            head = tempNode->next;
            head->prev = nullptr;
            delete tempNode;

            size--;
        }
    }
}

#endif //DOUBLELINKEDLIST_H

