//
// Created by Dominik on 15.10.2025.
//

#ifndef CircularDoubleLinkedList_H
#define CircularDoubleLinkedList_H
#include "Node.h"

template<typename T>
class CircularDoubleLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    CircularDoubleLinkedList();

    void add_front(T *object);
    void add_back(T *object);
    void del_front(bool free_space_yourself = true);
    void del_back(bool free_space_yourself = true);

    int get_size() const;
    Node<T>* get_head() const;
    Node<T>* get_tail() const;


};

template<typename T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {
}

template<typename T>
void CircularDoubleLinkedList<T>::add_front(T *object) {
    Node<T> *newNode = new Node<T>(object);

    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;

        size++;
    } else if (head == tail) {
        head = newNode;
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        tail->next = head;

        size++;
    } else {
        head->prev = newNode;
        tail->next = newNode;
        newNode->next = head;
        newNode->prev = tail;
        head = newNode;

        size++;
    }
}

template<typename T>
void CircularDoubleLinkedList<T>::add_back(T *object) {
    Node<T> *newNode = new Node<T>(object);

    if (!tail) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;

        size++;
    } else if (head == tail) {
        tail = newNode;
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        tail->next = head;

        size++;
    } else {
        head->prev = newNode;
        tail->next = newNode;
        newNode->next = head;
        newNode->prev = tail;
        tail = newNode;

        size++;
    }
}

template<typename T>
void CircularDoubleLinkedList<T>::del_front(bool free_space_yourself) {
    if (head) {
        if (head == tail) {
            if (free_space_yourself) delete head;
            if (free_space_yourself) delete tail;
            head = nullptr;
            tail = nullptr;

            size--;
        } else {
            Node<T>* temp_node = head;
            head = temp_node->next;
            head->prev = tail;
            tail->next = head;
            if (free_space_yourself) delete temp_node;

            size--;
        }
    }
}

template<typename T>
void CircularDoubleLinkedList<T>::del_back(bool free_space_yourself) {
    if (head) {
        if (head == tail) {
            if (free_space_yourself) delete head;
            if (free_space_yourself) delete tail;
            head = nullptr;
            tail = nullptr;

            size--;
        } else {
            Node<T>* temp_node = tail;
            tail = temp_node->prev;
            tail->next = head;
            head->prev = tail;
            if (free_space_yourself) delete temp_node;

            size--;
        }
    }
}

template<typename T>
int CircularDoubleLinkedList<T>::get_size() const {
    return size;
}

template<typename T>
Node<T>* CircularDoubleLinkedList<T>::get_head() const {
    return head;
}

template<typename T>
Node<T>* CircularDoubleLinkedList<T>::get_tail() const {
    return tail;
}

#endif //CircularDoubleLinkedList_H
