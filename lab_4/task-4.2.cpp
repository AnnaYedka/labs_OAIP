//
// Created by Анна Едка
// variant 10
//
#include <iostream>
#include <iomanip>

int main() {
    int n = 5, m = 5;
    int matrix[n][m];

    std::cout << "The program finds minimum element below the main diagonal\n";
    std::cout << "Enter " << n * m << " values: \n";

    // filling the array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
            //check of invalid input
            while (std::cin.fail()) {
                std::cout << "The input is invalid, try again\n";
                std::cout << "Enter another value ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> matrix[i][j];
            }
        }


    std::cout << "The matrix: ";
    for (int i = 0; i < n; i++) {
        std::cout << "\n";
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << matrix[i][j] << " ";
    }

    //finding the minimum value
    int min = matrix[1][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
    }
    std::cout << "\nThe minimum element: " << min;

        }
