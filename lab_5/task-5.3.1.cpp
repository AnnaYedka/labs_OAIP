//
// Created by Анна Едка
//

#include <iostream>
#include <iomanip>

void print_array(int** array, int n, int m){ // n, m - indexes of element in array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << "\n";
    }
}

void filling_new_array(int** array, int n, int m, int* new_array){
    int k = 0; // index of element in new array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if ( i == j && array[i][i] % 2 == 0){
                new_array[k] = array[i][i];
                k++;
            }
        }
    }
}

int main(){
    std::cout << "The program will create dynamic array of elements located on the main"
                 " diagonal of the matrix and having an even value.\n It will count the multiplication of all elements.\n "
                 "Enter the size of matrix n*k\n";
    int n, k;
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }
    std::cin >> k;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> k;
    }

    //creating a matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new int[k];
    }

    // filling the matrix
    std::cout << "Enter the values to fill the matrix: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
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

    int multiplication = 1, size = 0;// size of new array

    //finding multiplication and the size of new array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            multiplication *= matrix[i][j];
            if (i == j && matrix[i][j] % 2 == 0){
                size++;
            }
        }
    }


    std::cout << "Your matrix: \n";
    print_array(matrix, n, k);

    std::cout << "The result of multiplication of all elements: " << multiplication << "\n";

    //creating a new array only if there are elements, which fit the condition
    if (size == 0){
        std::cout << "There are no even values on the diagonal\n";
    }
    else {
        int* new_array = new int[size];
        filling_new_array(matrix, n, k, new_array);

        std::cout << "New array:\n";
        for (int i = 0; i < size; i++){
            std::cout << std::setw(4) << new_array[i];
        }
        delete[] new_array;
    }


    for (int i = 0; i < n; i++)
        delete matrix[i];
    delete[] matrix;
}
