//
// Created by Анна Едка
//
#include <iostream>
#include <iomanip>
int main(){
    int n, m;
    std::cout << "The program finds the amount of local minimums in matrix \n";
    std::cout << "Enter number of rows \n";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }
    std::cout << "Enter number of columns \n";
    std::cin >> m;
        //check of invalid input
        while (std::cin.fail()) {
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter another value ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> m;
        }

    // creating a matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    // filling the matrix
    std::cout << "Enter the values: ";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
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
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << matrix[i][j] << " ";
        std::cout << "\n";
    }


    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0){//left upper corner
                if (matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i][j + 1])
                    count++;}
            else if (i == (n - 1) && j == 0){// left lower corner
                if (matrix[i][j] < matrix[i - 1][j + 1] && matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i][j + 1])
                    count++;}
            else if (i == 0 && j == (m - 1)){// right upper corner
                if (matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i][j - 1])
                    count++;}
            else if (i == (n - 1) && j == (m - 1)){// right lower corner
                if (matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i][j - 1])
                    count++;}
            else if (i == 0){//upper row
                if (matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i][j + 1] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i][j - 1])
                    count++;}
            else if (j == 0){//left column
                if (matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i - 1][j + 1] && matrix[i][j] < matrix[i][j + 1] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i - 1][j])
                    count++;}
            else if (i == (n - 1)){//lower row
                if (matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i - 1][j + 1] && matrix[i][j] < matrix[i][j + 1] && matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i - 1][j])
                    count++;}
            else if (j == (m - 1)){//right column
                if (matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i - 1][j])
                    count++;}
            else
                if (matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i - 1][j + 1] && matrix[i][j] < matrix[i][j + 1] && matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i - 1][j])
                    count++;

        }
    }
    std::cout << "The amount of local minimums in matrix: " << count;

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}