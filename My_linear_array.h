#pragma once
#include <iostream>


template<typename T>
struct Node {
    Node *next; // указатель на следующий элемент Node
    Node *prev; // указатель на предыдущий элемент Node
    T data; // пользовательские данные (хранимый объект)
};

template<typename T>
class My_linear_array {
public:
    My_linear_array();
    My_linear_array(const My_linear_array<T> &array);
    void check_range(size_t n);

    void push_back(const T &n);

    void erase(size_t n);

    T get_first();
    T get_last();

    void insert(const T &n, size_t t);

    T &operator[](size_t n);
    size_t get_size();
    ~My_linear_array();

private:
    Node<T> *my_node;
    Node<T> *tmp_node;
    size_t m_size;
    Node<T> *last_node;
    Node<T> *first_node;
    size_t erase_count;
};



