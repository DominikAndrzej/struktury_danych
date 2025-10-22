//
// Created by Dominik on 15.10.2025.
//

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    Node* next;
    Node* prev;
    T value;

    Node(T value);
    ~Node();

    void toString();
};


template<typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template<typename T>
Node<T>::~Node() {

}

#endif //NODE_H
