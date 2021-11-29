//
// Created by Анна Едка
//
#include <iostream>
#include <iomanip>
void duplicates(int* array, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (array[i] == array[j] && i != j){
                for (int k = j; k < n; k++)
                    array[k] = array[k + 1];
                n--;
            }
    for (int i = 0; i < n; i++)
        std::cout << std::setw(3) << array[i] << " ";
}

int main(){
    std::cout << "The program removes the duplicates from array\n";
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
    int* a = new int[n];

    std::cout << "Enter the values: \n";
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << "Array without duplicates: ";
    duplicates(a, n);

    delete[] a;
}
