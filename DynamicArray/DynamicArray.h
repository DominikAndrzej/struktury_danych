//
// Created by Dominik on 03.12.2025.

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

/**
 *
 * @tparam T object of any class that overloads opeartors(<<, <, >, ==, <=, >=)
 * a dynamic Array that stores copies od objects
 */
template<typename T>
class DynamicArray {
private:
    int capacity;
    int size;
    T* array;
    int extension_param;

public:
    DynamicArray();

    int get_capacity() const;
    int get_size() const;

    void push_back(T* new_el);

    void print_list_simple();
    void change_el_at_index(int index, T* new_el);

    /**
     *
     * @param index
     * @return pointer to object from given index
     */
    T *operator[](int index) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range in operator[]");
        }

        return &array[index];
    }
};

template<typename T>
DynamicArray<T>::DynamicArray(): capacity(1), size(0), array(new T[capacity]), extension_param(2) {
}

template<typename T>
int DynamicArray<T>::get_capacity() const {
    return this->capacity;
}

template<typename T>
int DynamicArray<T>::get_size() const {
    return this->size;
}

template<typename T>
void DynamicArray<T>::push_back(T* new_el) {
    if (size < capacity) { // if there is a place for new element
        array[size] = *new_el;
        size ++;
    } else {
        capacity = capacity * extension_param; // extend capacity
        T* new_array = new T[capacity]; // create a new array

        for (int i=0; i<size; i++) {
            new_array[i] = array[i];
        } // move every element to a new array

        new_array[size] = *new_el; // add a new element
        size++;

        delete[] array; // delete old array

        array = new_array; // set this object array pointer to a new array

    }
}

template<typename T>
void DynamicArray<T>::print_list_simple() {
    std::cout << "List { size: " << size << "; capacity: " << capacity << "; elements: {";

    for (int i=0; i<size; i++) {
        std::cout << "\n\t" << array[i];
    }
    std::cout << "\n}\n";
}

template<typename T>
void DynamicArray<T>::change_el_at_index(int index, T* new_el) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range in operator[]");
    }

    array[index] = *new_el;
}

#endif //DYNAMICARRAY_H
