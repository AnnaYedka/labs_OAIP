//
// Created by Анна Едка
// variant 10
//

#include <iostream>
#include <iomanip>

int main(){
    std::cout << "The program finds the sum of the smallest elements of odd rows"
                 " and of the biggest elements of even rows\n";
    int n = 5;
    // creating a matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    std::cout << "Enter " << n * n << " values: \n";

    // filling the array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
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


    // printing the matrix
    std::cout << "The matrix: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << std::setw(2) << matrix[i][j] << " ";
        std::cout << "\n";
    }

    //finding the sum
    int sum = 0, min, max;
    for (int i = 0; i < n; i++){
        if ((i + 1) % 2 != 0){
            min = matrix[i][0];
            for (int j = 1; j < n; j++){
                if (matrix[i][j] < min)
                    min = matrix[i][j];
            }
            sum += min;
        }
        else {
            max = matrix[i][0];
            for (int j = 1; j < n; j++){
                if (matrix[i][j] > max)
                    max = matrix[i][j];
            }
            sum += max;
        }
    }


    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    std::cout << "The sum: " << sum;
}

