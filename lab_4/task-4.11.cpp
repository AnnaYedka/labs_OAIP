//
// Created by Анна Едка
//

#include <iostream>

int main(){
    std::cout << "The program will find the maximum sum of elements on the diagonal of cube array\n";
    std::cout << "Enter the size of cube: \n";
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

    // creating a matrix
    int*** arr = new int**[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int *[n];
        for (int j = 0; j < n; j++)
            arr[i][j] = new int[n];
    }

    // filling the matrix
    std::cout << "Enter the values to fill the array: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                std::cin >> arr[i][j][k];
                //check of invalid input
                while (std::cin.fail()) {
                    std::cout << "The input is invalid, try again\n";
                    std::cout << "Enter another value ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> arr[i][j][k];
                }
            }

    // counting the sums of elements
    int diag1 = 0, diag2 = 0, diag3 = 0, diag4 = 0;
    for (int i = 0; i < n; i++){
        diag1 += arr[i][i][i];
        diag2 += arr[i][n - i - 1][i];
        diag3 += arr[i][i][n - i - 1];
        diag4 += arr[i][n - i - 1][n - i - 1];
    }

    // comparing the sums
    int max1, max2, max; // max1, max2 for comparison
    (diag1 > diag2)? max1 = diag1 : max1 = diag2;
    (diag3 > diag4)? max2 = diag3 : max2 = diag4;
    (max1 > max2)? max = max1 : max = max2;
    std::cout << "The maximum sum: " << max;

    //removing the matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            delete arr[i][j];
        delete arr[i];
    }
    delete[] arr;
}
