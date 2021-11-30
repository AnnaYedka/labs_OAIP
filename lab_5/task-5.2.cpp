//
// Created by Анна Едка
// variant 10
// dynamic library is used in this task, code of the library is in directory "lib_source"
//

#include <iostream>
#include "lib_source/dynamic_lib.h"

int main(){
    std::cout << "The program will find the amount of element in array which meet the condition: cos(a^2) > 0 and a < 0\n";
    std::cout << "Enter the size of array: \n";
    int n;
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

    std::cout << "Enter the elements of array: \n";
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
        //check of invalid input
        while (std::cin.fail()) {
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter another value ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> arr[i];
        }
    }

    std::cout << "There are " << count(arr, 0, n - 1) << " elements, which meet the condition\n";

    delete[] arr;
}