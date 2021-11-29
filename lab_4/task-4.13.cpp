//
// Created by Анна Едка
//

#include <iostream>
int main(){
    std::cout << "The program will supply how many inputs can\n"
                 " be obtained by optimally connecting N extension\n"
                 " cords such that the i-th extension cord has a [i] inputs.\n";
    std::cout << "Enter the number of extension cords: \n";
    int n;
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail() || n < 0) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }

    //creating and filling the array
    int* cord = new int[n];
    for (int i = 0; i < n; i++){
        std::cout << "Enter the number of inputs in " << i + 1 << " extension\n";
        std::cin >> cord[i];
        //check of invalid input
        while (std::cin.fail() || n < 0) {
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter another value ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> cord[i];
        }
    }

    int num_inputs = 0;
    for (int i = 0; i < n; i++)
        num_inputs += cord[i] - 1;

    std::cout << "The number of inputs: " << num_inputs + 1;
    delete[] cord;
}
