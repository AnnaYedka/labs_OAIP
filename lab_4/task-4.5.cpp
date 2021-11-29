//
// Created by Анна Едка
//

#include <iostream>
#include <iomanip>
int main() {
    int n, m;
    std::cout << "The program creates a new matrix, which element is an average of neighbors of initial matrix \n";
    std::cout << "Enter number of rows \n";
    std::cin >> n;
    std::cout << "Enter number of columns \n";
    std::cin >> m;

    // creating a matrix
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    //creating NEW matrix
    double** nmat = new double* [n];
    for (int i = 0; i < n; i++)
        nmat[i] = new double[m];

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

    // printing the matrix
    std::cout << "The matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << matrix[i][j] << " ";
        std::cout << "\n";
    }

    //filling NEW matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {//left upper corner
                nmat[i][j] = (matrix[i + 1][j + 1] + matrix[i + 1][j] + matrix[i][j + 1]) / 3.;

            } else if (i == (n - 1) && j == 0) {// left lower corner
                nmat[i][j] = (matrix[i - 1][j + 1] + matrix[i - 1][j] + matrix[i][j + 1]) / 3.;

            } else if (i == 0 && j == (m - 1)) {// right upper corner
                nmat[i][j] = (matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i][j - 1]) / 3.;

            } else if (i == (n - 1) && j == (m - 1)) {// right lower corner
                nmat[i][j] = (matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i][j - 1]) / 3.;

            } else if (i == 0) {//upper row
                nmat[i][j] = (matrix[i + 1][j + 1] + matrix[i + 1][j - 1] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i][j - 1]) / 5.;

            } else if (j == 0) {//left column
                nmat[i][j] = (matrix[i + 1][j + 1] + matrix[i - 1][j + 1] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i - 1][j]) / 5.;

            } else if (i == (n - 1)) {//lower row
                nmat[i][j] = (matrix[i - 1][j - 1] + matrix[i - 1][j + 1] + matrix[i][j + 1] + matrix[i][j - 1] + matrix[i - 1][j]) / 5.;

            } else if (j == (m - 1)) {//right column
                nmat[i][j] = (matrix[i - 1][j - 1] + matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i][j - 1] + matrix[i - 1][j]) / 5.;

            } else
                nmat[i][j] = (matrix[i + 1][j + 1] + matrix[i - 1][j - 1] + matrix[i + 1][j - 1] + matrix[i - 1][j + 1] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i][j - 1] + matrix[i - 1][j]) / 8.;
        }
    }

    //printing NEW matrix
    std::cout << "The NEW matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << std::setw(8) << nmat[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < n; i++)
        delete[] nmat[i];
    delete[] nmat;
}
