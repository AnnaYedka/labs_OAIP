//
// Created by Анна Едка
//

#include <iostream>
#include <iomanip>

int main(){
    std::cout << "The program creates a new matrix which element is maximum"
                 " value from elements that are on positions"
                 "to the left and upper \n";
    std::cout << "Enter the size of matrix N*M: \n";
    int n, m;
    std::cin >> n >> m;

    // creating a matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    // filling the matrix
    std::cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
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
    }

    // creating a new matrix
    int** answ = new int*[n];
    for (int i = 0; i < n; i++)
        answ[i] = new int[m];

    int max; // current max value
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            max = 0;
            for (int k = 0; k <= i; k++)
                for (int f = 0; f <= j; f++)
                    if (matrix[k][f] > max)
                        max = matrix[k][f];
            answ[i][j] = max;
        }

    // printing the matrix
    std::cout << "Your matrix: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << matrix[i][j] << " ";
        std::cout << "\n";
    }

    // printing new matrix
    std::cout << "New matrix: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << answ[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < n; i++)
        delete[] answ[i];
    delete[] answ;

}
