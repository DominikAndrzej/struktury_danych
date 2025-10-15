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
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
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
 * remove node from the front of the list
 */
template<typename T>
void DoubleLinkedList<T>::rmvFront() {

    // removing is possible only if the front node (head) exists
    if (head) {
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

