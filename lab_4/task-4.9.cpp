//
// Created by Анна Едка on 6.11.21.
//

#include <iostream>
#include <iomanip>
int main() {
    int n, m;
    std::cout << "The program will multiplicate 2 matrix\n";
    std::cout << "Enter the size of first matrix N*M: \n";
    std::cin >> n >> m;
    // creating matrix A
    int **A = new int *[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[m];

    // creating matrix B
    int **B = new int *[m];
    for (int i = 0; i < m; i++)
        B[i] = new int[n];

    std::cout << "Enter " << n * m << " values for the first matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
            //check of invalid input
            while (std::cin.fail()) {
                std::cout << "The input is invalid, try again\n";
                std::cout << "Enter another value ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> A[i][j];
            }
        }
    }

    std::cout << "Enter " << n * m << " values for the second matrix: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> B[i][j];
            //check of invalid input
            while (std::cin.fail()) {
                std::cout << "The input is invalid, try again\n";
                std::cout << "Enter another value ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> B[i][j];
            }
        }
    }

    // creating matrix for the answer
    int **answ = new int *[n];
    for (int i = 0; i < n; i++)
        answ[i] = new int[n];

    int elem;//element of matrix

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            elem = 0;
            for (int k = 0; k < m; k++)
                elem += A[i][k] * B[k][j];
            answ[i][j] = elem;
        }
    // printing the matrix A
    std::cout << "The matrix A: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << std::setw(3) << A[i][j] << " ";
        std::cout << "\n";
    }

    // printing the matrix B
    std::cout << "The matrix B: \n";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            std::cout << std::setw(3) << B[i][j] << " ";
        std::cout << "\n";
    }

    // printing the result of multiplication
    std::cout << "The result of multiplication: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << std::setw(3) << answ[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < n; i++)
        delete[] answ[i];
    delete[] answ;
}
