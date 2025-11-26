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
        os <<
            "(Node)"
            "\taddress: " << &node << "\n"
            "\tbody: " << *node.body << "\n"
            "\t\tPrevious node:\n"
            "\t\t\taddress: " << node.prev << "\n"
            "\t\t\tbody: " << *node.prev->body << "\n"
            "\t\tNext node:\n"
            "\t\t\taddress: " << node.next << "\n"
            "\t\t\tbody: " << *node.next->body << "\n"  << std::endl;
        return os;
    }
};

template<typename T>
Node<T>::Node(T* value) : next(nullptr), prev(nullptr), body(value) {}

template<typename T>
Node<T>::~Node() {
}



#endif //NODE_H
