//
// Created by Анна Едка
//

#include <iostream>
#include <iomanip>


void print_array(int** array, int n, int m) { // n, m - indexes of element in array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << "\n";
    }
}

double average(int** array, int n, int m){
    double sum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            sum += array[i][j];
        }
    }
    return sum / (n * m);
}

void filling_new_array(int** array, int n, int m, int* new_array){
    int k = 0; // index of element in new array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j += 2){
            if (array[i][j] % 2 == 1){
                new_array[k] = array[i][j];
                k++;
            }
        }
    }
}

int main() {
    std::cout << "The program will create a new array from odd elements"
                 " of even columns of first array and find average of all elements\n";
    std::cout << "Enter the size of array n*m\n";
    int n, m;
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }
    std::cin >> m;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> m;
    }

    //creating an array
    int **array = new int *[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }


    // filling the array
    std::cout << "Enter the values to fill the matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> array[i][j];
            //check of invalid input
            while (std::cin.fail()) {
                std::cout << "The input is invalid, try again\n";
                std::cout << "Enter another value ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> array[i][j];
            }
        }
    }

    int size = 0; // size of new array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j += 2){
            if (array[i][j] % 2 == 1){
                size++;
            }
        }
    }

    std::cout << "Your array: \n";
    print_array(array, n, m);


    //new array
    if (size == 0){
        std::cout << "There are no odd elements in even columns\n";
    }
    else {
        int* new_array = new int[size];
        filling_new_array(array, n, m, new_array);
        std::cout << "The new array:\n";
        for (int i = 0; i < size; i++){
            std::cout << std::setw(4) << new_array[i];
        }
        std::cout << "\n";
        delete[] new_array;
    }

    std::cout << "The average of elements: " << average(array, n, m);

    for (int i = 0; i < n; i++)
        delete array[i];
    delete[] array;

}