//
// Created by Анна Едка
// variant 10
// static library is used in this task, code of the library is in directory "lib_source"
//

#include <iostream>
#include "lib_source/static_lib.h"

int main(){
    int n;
    std::cout << "The program will create an array of size n with a specific function\n";
    std::cout << "Enter n\n";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }

    double* arr = new double[n];

    creating_array1(arr, n);

    creating_array2(arr, n);

    delete[] arr;
}
