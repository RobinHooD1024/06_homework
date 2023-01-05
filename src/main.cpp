#include <iostream>
#include "My_linear_array.h"
#include "My_linear_array.cpp"
#include "Dynamic_array.h"
#include "Dynamic_array.cpp"
#include "My_linear_array_one_way.h"
#include "My_linear_array_one_way.cpp"

int main() {

    DynamicArray<int> my_int_array;
    My_linear_array<int> my_linear_array;
    My_linear_array_one_way<int> my_linear_array_one_way;
    for (int i = 0; i < 10; ++i) {
        my_int_array.push_back(i);
        my_linear_array.push_back(i);
        my_linear_array_one_way.push_back(i);
    }
    try {
        std::cout << my_int_array << std::endl;
        std::cout << my_int_array.get_size() << std::endl;
        my_int_array.erase(2);
        my_int_array.erase(4);
        my_int_array.erase(6);
        std::cout << my_int_array << std::endl;
        my_int_array.insert(10, 0);
        std::cout << my_int_array << std::endl;
        my_int_array.insert(20, my_int_array.get_size() / 2);
        std::cout << my_int_array << std::endl;
        my_int_array.push_back(30);
        std::cout << my_int_array << std::endl;
        std::cout << "========================================\n";
        std::cout << my_linear_array << std::endl;
        std::cout << my_linear_array.get_size() << std::endl;
        my_linear_array.erase(2);
        my_linear_array.erase(4);
        my_linear_array.erase(6);
        std::cout << my_linear_array << std::endl;
        my_linear_array.insert(10, 0);
        std::cout << my_linear_array << std::endl;
        my_linear_array.insert(20, my_linear_array.get_size() / 2);
        std::cout << my_linear_array << std::endl;
        my_linear_array.push_back(30);
        std::cout << my_linear_array << std::endl;
        std::cout << "========================================\n";
        std::cout << my_linear_array_one_way << std::endl;
        std::cout << my_linear_array_one_way.get_size() << std::endl;
        my_linear_array_one_way.erase(2);
        my_linear_array_one_way.erase(4);
        my_linear_array_one_way.erase(6);
        std::cout << my_linear_array_one_way << std::endl;
        my_linear_array_one_way.insert(10, 0);
        std::cout << my_linear_array_one_way << std::endl;
        my_linear_array_one_way.insert(20, my_linear_array_one_way.get_size() / 2);
        std::cout << my_linear_array_one_way << std::endl;
        my_linear_array_one_way.push_back(30);
        std::cout << my_linear_array_one_way << std::endl;
        std::cout << "=====================" << std::endl;
        std::cout << my_int_array.get_first() << std::endl;
        std::cout << my_int_array.get_last() << std::endl;
        std::cout << my_linear_array_one_way.get_first() << std::endl;
        std::cout << my_linear_array_one_way.get_last() << std::endl;
        std::cout << my_linear_array.get_first() << std::endl;
        std::cout << my_linear_array.get_last() << std::endl;
        std::cout << my_int_array[3] << std::endl;
        std::cout << my_linear_array[3] << std::endl;
        std::cout << my_linear_array_one_way[3] << std::endl;


        DynamicArray<int> copy {my_int_array};
        DynamicArray<int> copy_2;
        copy_2 = copy;
        std::cout << copy.get_last() << std::endl;
        std::cout << copy[3] << std::endl;
        std::cout << "=====================" << std::endl;
        My_linear_array<int> copy2 {my_linear_array};
        std::cout << copy2.get_last() << std::endl;
        std::cout << copy2[3];
        std::cout << copy2[13];

    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}
