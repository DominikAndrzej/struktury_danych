//
// Created by Dominik on 15.10.2025.
//

#ifndef CircularDoubleLinkedList_H
#define CircularDoubleLinkedList_H
#include "Node.h"
#include "../Enums/Sort_enum.cpp"

template<typename T>
class CircularDoubleLinkedList {
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    CircularDoubleLinkedList();

    void add_front(T *object);

    void add_back(T *object);

    void del_front(bool free_space_yourself = true);

    void del_back(bool free_space_yourself_cond = true);

    int get_size() const;

    Node<T> *get_head() const;

    Node<T> *get_tail() const;

    void setValue(int index, T *newElement);

    Node<T> *find_node_with_element(T *element);

    bool del_node_with_element(T *element, bool free_space_yourself_cond = true);

    void add_in_order(T *new_element, Sort_enum sort_way = Sort_enum::ASC);

    void print_all_nodes();

    T *&operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range in operator[]");
        }

        Node<T> *thisNode = head; // index 0

        for (int i = 1; i <= index; i++) {
            thisNode = thisNode->next;
        }

        return thisNode->body;
    }
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
            Node<T> *temp_node = head;
            head = temp_node->next;
            head->prev = tail;
            tail->next = head;
            if (free_space_yourself) delete temp_node;

            size--;
        }
    }
}

template<typename T>
void CircularDoubleLinkedList<T>::del_back(bool free_space_yourself_cond) {
    if (head) {
        if (head == tail) {
            if (free_space_yourself_cond) delete head;
            if (free_space_yourself_cond) delete tail;
            head = nullptr;
            tail = nullptr;

            size--;
        } else {
            Node<T> *temp_node = tail;
            tail = temp_node->prev;
            tail->next = head;
            head->prev = tail;
            if (free_space_yourself_cond) delete temp_node;

            size--;
        }
    }
}

template<typename T>
int CircularDoubleLinkedList<T>::get_size() const {
    return size;
}

template<typename T>
Node<T> *CircularDoubleLinkedList<T>::get_head() const {
    return head;
}

template<typename T>
Node<T> *CircularDoubleLinkedList<T>::get_tail() const {
    return tail;
}

template<typename T>
void CircularDoubleLinkedList<T>::setValue(int index, T *newElement) {
    (*this)[index] = newElement;
}

template<typename T>
Node<T> *CircularDoubleLinkedList<T>::find_node_with_element(T *element) {
    Node<T> *thisNode = head;

    for (int i = 0; i < size; i++) {
        if (*thisNode->body == *element) {
            return thisNode;
        }
        thisNode = thisNode->next;
    }
    return nullptr;
}

template<typename T>
bool CircularDoubleLinkedList<T>::del_node_with_element(T *element, bool free_space_yourself_cond) {
    Node<T> *node_to_del = find_node_with_element(element);

    if (node_to_del) {
        if (node_to_del == head && node_to_del == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (node_to_del == head) {
            head = node_to_del->next;
            head->prev = tail;
            tail->next = head;
        } else if (node_to_del == tail) {
            tail = node_to_del->prev;
            tail->next = head;
            head->prev = tail;
        } else {
            node_to_del->prev->next = node_to_del->next;
            node_to_del->next->prev = node_to_del->prev;
        }
        size--;
        return true;
    }
    return false;
}

template<typename T>
void CircularDoubleLinkedList<T>::add_in_order(T *new_element, Sort_enum sort_way) {
    // for now, I'm resigning from sorting my list, because it's complicated, I just add an element in first matching place
    Node<T> *current_node = head;
    Node<T> *new_node = new Node<T>(new_element);

    switch (sort_way) {
        case ASC:
            while (true) {
                if (new_node->body <= current_node->body) {
                    new_node->prev = current_node->prev;
                    new_node->next = current_node;

                    current_node->prev->next = new_node;
                    current_node->prev = new_node;

                    if (current_node == head) {
                        head = new_node;
                    }

                    size++;
                    break;
                }

                current_node = current_node->next;
                if (current_node == head) { // repeated iteration on head
                    add_back(new_element); // if the algorithm looped on a list, it means a new element is bigger than anything else, so add it at back
                    break;
                }
            }
            break;
        case DESC:
            while (true) {
                if (new_node->body >= current_node->body) {
                    new_node->prev = current_node->prev;
                    new_node->next = current_node;

                    current_node->prev->next = new_node;
                    current_node->prev = new_node;

                    if (current_node == head) {
                        head = new_node;
                    }

                    size++;
                    break;
                }

                current_node = current_node->next;
                if (current_node == head) { // repeated iteration on head
                    add_back(new_element); // if the algorithm looped on a list, it means a new element is smaller than anything else, so add it at back
                    break;
                }
            }
            break;
    }
}

template<typename T>
void CircularDoubleLinkedList<T>::print_all_nodes() {
    Node<T>* current_node = tail;
    do {
        current_node = current_node->next;

        std::cout << *current_node << std::endl;

    } while (current_node != tail);
}

#endif //CircularDoubleLinkedList_H
