#pragma once
#include <iostream>

template<typename T>
class DynamicArray {
public:
    DynamicArray();
    DynamicArray(const DynamicArray &array);
    void push_back(const T &n);
    void push_front(const T &n);
    void insert(const T &n, size_t pos);
    void check_capacity();
    void check_range(size_t n);
    T get_data(size_t n);
    void erase_data(const T &n);
    void erase(size_t n);
    size_t get_size();
    size_t getCap();
    ~DynamicArray();
    T get_first();
    T get_last();

    T &operator[](size_t n);
    DynamicArray &operator=(const DynamicArray<T> &array);
    bool operator==(const DynamicArray<T> &array);

private:
    size_t m_size;
    size_t m_capacity;
    T *m_data;
    size_t m_delete_counter;
};

