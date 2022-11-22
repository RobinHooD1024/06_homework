#include "My_linear_array_one_way.h"

template <typename T>
My_linear_array_one_way<T>::My_linear_array_one_way() : m_size{0}, my_node(new Node<T>), erase_count{0} {
    my_node->next = nullptr;
    my_node->data = 0;
};

template <typename T>
void My_linear_array_one_way<T>::check_range(size_t n) {
    if (n >= m_size || n < 0) {
        throw "Out of range";
    }
}

template <typename T>
void My_linear_array_one_way<T>::push_back(T n) {
    if (m_size == 0) {
        my_node->data = n;
        m_size++;
        first_node = my_node;
    } else {
        Node<T> *new_node = new Node<T>;
        new_node->next = nullptr;
        my_node = first_node;
        for (size_t i = 1; i < m_size; i++) {
            my_node = my_node->next;
        }
        my_node->next = new_node;
        new_node->data = n;
        last_node = new_node;
        m_size++;
    }
}

template <typename T>
T My_linear_array_one_way<T>::get_first() {
    return first_node->data;
}

template <typename T>
T My_linear_array_one_way<T>::get_last() {
    return last_node->data;
}

template <typename T>
void My_linear_array_one_way<T>::erase(size_t n) {
    check_range(n);
    my_node = first_node;
    n -= erase_count;
    while (n > 0) {
        tmp_node = my_node;
        my_node = my_node->next;
        n--;
    }
    tmp_node->next = my_node->next;
    delete my_node;
    m_size--;
    erase_count++;
}

template <typename T>
void My_linear_array_one_way<T>::insert(T n, size_t t) {
    check_range(t);
    my_node = first_node;
    while (t > 0) {
        tmp_node = my_node;
        my_node = my_node->next;
        t--;
    }
    Node<T> *new_node = new Node<T>;
    if (my_node == first_node) {
        new_node->next = first_node;
        new_node->data = n;
        first_node = new_node;
    } else {
        tmp_node->next = new_node;
        new_node->next = my_node;
        new_node->data = n;
    }
    m_size++;
}

template <typename T>
T &My_linear_array_one_way<T>::operator[](size_t n) {
    check_range(n);
    my_node = first_node;
    while (n > 0) {
        my_node = my_node->next;
        n--;
    }
    return my_node->data;
}

template <typename T>
size_t My_linear_array_one_way<T>::get_size() { return m_size; }

template<typename T>
std::ostream &operator<<(std::ostream &os, My_linear_array_one_way<T> &array) {
    for (size_t i = 0; i < array.get_size(); i++) {
        os << array[i] << " ";
    }
    return os;
}

template <typename T>
My_linear_array_one_way<T>::~My_linear_array_one_way<T>() {
    my_node = first_node;
    do {
        tmp_node = my_node;
        my_node = my_node->next;
        delete tmp_node;
    } while (my_node != nullptr);
}