//
// Created by Анна Едка
//
#include <iostream>
#include <iomanip>

int main(){
    int n, m;
    std::cout << "The program makes a sapper game \n";
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

    char** field = new char* [n];
    for (int i = 0; i < n; i++)
        field[i] = new char[m];

    // filling the matrix
    std::cout << "Enter '*' or '.' to fill the field ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> field[i][j];
            //check of invalid input
            while (std::cin.fail() || field[i][j] != '*' && field[i][j] != '.') {
                std::cout << "The input is invalid, try again\n";
                std::cout << "Enter another value ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> field[i][j];
            }
        }
    }

    // printing the old field
    std::cout << "The OLD field: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << field[i][j] << " ";
        std::cout << "\n";
    }

    int count;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            count = 48; // count = 0
            if (field[i][j] != '*'){
                //check of the neighbours
                for (int x = i - 1; x <= i + 1; x++)
                    for (int y = j - 1; y <= j + 1; y++)
                        if(x >= 0 && y >= 0 && x < n && y < m && field[x][y] == '*')
                            count++;
                field[i][j] = count;
            }
        }

    // printing the new field
    std::cout << "The NEW field: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            std::cout << std::setw(2) << field[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < n; i++)
        delete field[i];
    delete[] field;

}
