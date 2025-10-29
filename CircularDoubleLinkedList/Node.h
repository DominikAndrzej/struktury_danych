//
// Created by Dominik on 15.10.2025.
//

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    Node* next;
    Node* prev;
    T* body;

    Node(T* value);
    ~Node();

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << "Previous node address: " << &node.prev << ", this node address: " << &node << ", next node address: " << &node.next;
        return os;
    }
};

template<typename T>
Node<T>::Node(T* value) : body(value), next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::~Node() {
    delete body;
}



#endif //NODE_H
