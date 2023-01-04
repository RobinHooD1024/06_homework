#pragma once
#include <iostream>

template<typename T>
class My_linear_array_one_way {
public:
    My_linear_array_one_way();
    void check_range(size_t n);
    void push_back(const T &n);
    void erase(size_t n);
    void insert(const T &n, size_t t);
    T get_first();
    T get_last();
    T &operator[](size_t n);
    size_t get_size();
    ~My_linear_array_one_way<T>();

private:
    Node<T> *my_node;
    Node<T> *tmp_node;
    size_t m_size;
    Node<T> *first_node;
    size_t erase_count;
    Node<T> *last_node;
};



