#include "My_linear_array.h"

template <typename T>
My_linear_array<T>::My_linear_array() : m_size{0}, my_node(new Node<T>), erase_count{0} {
    my_node->next = nullptr;
    my_node->prev = nullptr;
    my_node->data = 0;
    last_node = first_node = my_node;
};

template <typename T>
My_linear_array<T>::My_linear_array(const My_linear_array<T> &array) : m_size{array.m_size}, erase_count{array.erase_count} {
    first_node = new Node<T>;
    first_node->data = array.first_node->data;
    my_node = first_node;
    tmp_node = array.first_node->next;
    while (tmp_node != nullptr) {
        Node<T> *tmp = new Node<T>;
        my_node->next = tmp;
        tmp->prev = my_node;
        tmp->data = tmp_node->data;
        my_node = tmp;
        tmp_node = tmp_node->next;
    }
    last_node = my_node;
    last_node->next = nullptr;
};

template <typename T>
void My_linear_array<T>::check_range(size_t n) {
    if (n >= m_size || n < 0) {
        throw std::out_of_range ("Out of range");
    }
}

template <typename T>
void My_linear_array<T>::push_back(const T &n) {
    if (m_size == 0) {
        my_node->data = n;
        m_size++;
    } else {
        Node<T> *new_node = new Node<T>;
        new_node->next = nullptr;
        last_node->next = new_node;
        new_node->data = n;
        new_node->prev = last_node;
        last_node = new_node;
        m_size++;
    }
}

template <typename T>
T My_linear_array<T>::get_first() {
    return first_node->data;
}

template <typename T>
T My_linear_array<T>::get_last() {
    return last_node->data;
}

template <typename T>
void My_linear_array<T>::erase(size_t n) {
    check_range(n);
    my_node = first_node;
    n -= erase_count;
    while (n > 0) {
        my_node = my_node->next;
        n--;
    }
    tmp_node = my_node->prev;
    tmp_node->next = my_node->next;
    tmp_node = my_node->next;
    tmp_node->prev = my_node->prev;
    delete my_node;
    m_size--;
    erase_count++;
}

template <typename T>
void My_linear_array<T>::insert(const T &n, size_t t) {
    check_range(t);
    my_node = first_node;
    while (t > 0) {
        my_node = my_node->next;
        t--;
    }
    Node<T> *new_node = new Node<T>;
    if (my_node == first_node) {
        new_node->next = first_node;
        new_node->prev = nullptr;
        first_node->prev = new_node;
        new_node->data = n;
        first_node = new_node;
    } else {
        tmp_node = my_node->prev;
        tmp_node->next = new_node;
        new_node->prev = my_node->prev;
        new_node->next = my_node;
        my_node->prev = new_node;
        new_node->data = n;
    }
    m_size++;
}

template <typename T>
T &My_linear_array<T>::operator[](size_t n) {
    check_range(n);
    my_node = first_node;
    while (n > 0) {
        my_node = my_node->next;
        n--;
    }
    return my_node->data;
}

template <typename T>
size_t My_linear_array<T>::get_size() { return m_size; }

template<typename T>
std::ostream &operator<<(std::ostream &os, My_linear_array<T> &array) {
    for (size_t i = 0; i < array.get_size(); i++) {
        os << array[i] << " ";
    }
    return os;
}

template <typename T>
My_linear_array<T>::~My_linear_array<T>() {
    my_node = first_node;
    do {
        tmp_node = my_node;
        my_node = my_node->next;
        delete tmp_node;
    } while (my_node != nullptr);
}