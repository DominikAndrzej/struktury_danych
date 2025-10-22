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
    T* value;

    explicit Node(T* value);
    ~Node();



    void toString();
};


template<typename T>
Node<T>::Node(T* value) : next(nullptr), prev(nullptr), value(value) {}

template<typename T>
Node<T>::~Node() {
    delete value;
}

template<typename T>
void Node<T>::toString() {

}

#endif //NODE_H
