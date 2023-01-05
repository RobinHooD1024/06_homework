#include "Dynamic_array.h"

template <typename T>
DynamicArray<T>::DynamicArray() : m_size{0}, m_capacity{0}, m_data{nullptr}, m_delete_counter{0} {};

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray &array) : m_size{array.m_size}, m_capacity{array.m_capacity}, m_delete_counter{array.m_delete_counter} {
    m_data = new T [m_size];
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = array.m_data[i];
    }
}

template <typename T>
void DynamicArray<T>::insert(const T &n, size_t pos) {
    check_capacity();
    for (size_t i = m_size;i>pos; i--) {
        m_data[i] = m_data[i-1];
    }
    m_data[pos] = n;
    m_size++;
}

template <typename T>
void DynamicArray<T>:: push_back(const T &n) {
    check_capacity();
    m_data[m_size] = n;
    m_size++;
}

template <typename T>
void DynamicArray<T>::check_capacity() {
    if (m_capacity == 0) {
        T *new_memory = new T[10];
        m_capacity = 10;
        m_data = new_memory;
    } else if (m_size == m_capacity) {
        m_capacity *= 1.5;
        T *new_memory = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            new_memory[i] = m_data[i];
        }
        m_data = new_memory;
    } else {
        return;
    }
}

template <typename T>
void DynamicArray<T>::check_range(size_t n) {
    if (n  >= m_size || n < 0) {
        throw std::out_of_range ("Out of range");
    }
}

template <typename T>
T DynamicArray<T>::get_data(size_t n) {
    check_range(n);
    return m_data[n];
}

template <typename T>
void DynamicArray<T>::erase_data(const T &n) {
    for (size_t i = 0; i < m_size; i++) {
        if (m_data[i] == n) {
            for (size_t j = i+1; j < m_size; j++) {
                m_data[j-1] = m_data[j];
            }
            m_size--;
        }
    }
}

template <typename T>
void DynamicArray<T>::erase(size_t n) {
    check_range(n);
    n-=m_delete_counter;
    for (size_t j = n+1; j < m_size; j++) {
        m_data[j-1] = m_data[j];
    }
    m_size--;
    m_delete_counter++;
}

template <typename T>
size_t DynamicArray<T>:: get_size() {return m_size;}

template <typename T>
size_t DynamicArray<T>::getCap() {return m_capacity;}

template <typename T>
DynamicArray<T>::~DynamicArray() {delete[] m_data;}

template <typename T>
T &DynamicArray<T>::operator[](size_t n) {
    check_range(n);
    return m_data[n];
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &array) {
    if (this == array) {
        return *this;
    }
    m_size = array.m_size;
    m_capacity = array.m_capacity;
    m_delete_counter = array.m_delete_counter;
    delete *m_data;
    m_data = new T[m_size];
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = array.m_data[i];
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, DynamicArray<T> &array) {
    for (size_t i = 0; i < array.get_size(); i++) {
        os << array[i] << " ";
    }
    return os;
}

template <typename T>
T DynamicArray<T>::get_first() {return m_data[0];}

template <typename T>
T DynamicArray<T>::get_last() {return m_data[m_size-1];}