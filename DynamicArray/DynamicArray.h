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
    ~DynamicArray();

    bool empty() const {return size == 0;}

    int get_capacity() const;
    int get_size() const;

    void push_back(const T& new_el);

    void print_list_simple();
    void print_list_very_simple();
    void change_el_at_index(int index,const T& new_el);

    void bubble_sort(Sort_enum sort_way = ASC);

    void clear(bool hard_reset = false);

    /**
     *
     * @param index
     * @return pointer to object from given index
     */
    T& operator[](int index) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range in operator[]");
        }

        return array[index];
    }
};

template<typename T>
DynamicArray<T>::DynamicArray(): capacity(1), size(0), array(new T[capacity]), extension_param(2) {
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
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
void DynamicArray<T>::push_back(const T& new_el) {
    if (size < capacity) { // if there is a place for new element
        array[size] = new_el;
        size ++;
    } else {
        capacity = capacity * extension_param; // extend capacity
        T* new_array = new T[capacity]; // create a new array

        for (int i=0; i<size; i++) {
            new_array[i] = array[i];
        } // move every element to a new array

        new_array[size] = new_el; // add a new element
        size++;

        delete[] array; // delete old array
        array = new_array; // set this object array pointer to a new array

    }
}

template<typename T>
void DynamicArray<T>::print_list_simple() {
    std::cout << "List { size: " << size << "; capacity: " << capacity << "; elements: {";

    for (int i = 0; i < size; i++) {
        std::cout << "\n\t";

        if constexpr (std::is_pointer<T>::value) {
            std::cout << array[i] << " that points to a value: "<< *array[i];
        } else {
            std::cout << array[i];
        }
    }

    std::cout << "\n}\n";
}

template<typename T>
void DynamicArray<T>::print_list_very_simple() {
    std::cout << "List { size: " << size << "; capacity: " << capacity << "}\n";
}


template<typename T>
void DynamicArray<T>::change_el_at_index(int index,const T& new_el) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range in operator[]");
    }

    array[index] = new_el;
}

template<typename T>
void DynamicArray<T>::bubble_sort(Sort_enum sort_way) {
    if (empty()) return;

    for (int i = size - 1; i > 0; i--) {
        bool swapped = false;

        for (int j = 0; j < i; j++) {
            bool must_swap = false;

            if (sort_way == ASC) {
                if (array[j] > array[j + 1]) must_swap = true;
            } else {
                if (array[j] < array[j + 1]) must_swap = true;
            }

             if (must_swap) {
                // T buffor = array[j];
                // array[j] = array[j+1];
                // array[j+1] = buffor;
                 std::swap(array[j], array[j+1]);
                 swapped = true;
            }
        }

        if (!swapped) break;
    }
}

template<typename T>
void DynamicArray<T>::clear(bool hard_reset) {
    if (hard_reset) {
        delete[] array;
        size = 0;
        capacity = 1;
        array = new T[capacity];
    } else {
        size = 0;
    }
}

#endif //DYNAMICARRAY_H
