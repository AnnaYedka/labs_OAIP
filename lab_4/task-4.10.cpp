//
// Created by Анна Едка
//

#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cout << "The program makes a magic square\n";
    std::cout << "Enter the size of square (it should be odd):\n";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail() || n % 2 == 0) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }

    // creating a matrix
    int size = 2 * n - 1;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    for (int i = 0; i < (size); i++)
        for (int j = 0; j < (size); j++)
            matrix[i][j] = 0;

    int y = (size - 1) / 2, x = 0, y0 = (size - 1) / 2, x0 = 0;// indexes of the beginning of the diagonal
    for (int k = 1; k <= n * n; k++){
        matrix[y][x] = k;
        y--;
        x++;
        if (k % n == 0){ // moving to the next diagonal
            y0 += 1;
            y = y0;
            x0 += 1;
            x = x0;
        }
    }

    //moving the triangles
    int border_up = n / 2;
    int border_down = size - n / 2 - 1;
    int border_left = n / 2;
    int border_right = size - n / 2 - 1;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++){
            if (j < border_left && matrix[i][j] != 0)//left triangle
                matrix[i][j + n] = matrix[i][j];
            else if (j > border_right && matrix[i][j] != 0)//right triangle
                matrix[i][j - n] = matrix[i][j];
            else if (i < border_up && matrix[i][j] != 0)//up triangle
                matrix[i + n][j] = matrix[i][j];
            else if ( i > border_down && matrix[i][j] != 0)//down triangle
                matrix[i - n][j] = matrix[i][j];
        }

    // printing the matrix
    std::cout << "The magic square: \n";
    for (int i = border_up; i <= border_down; i++){
        for (int j = border_left; j <= border_right; j++)
            std::cout << std::setw(3) << matrix[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;

}