//
// Created by Анна Едка
//


#include <iostream>
#include <iomanip>


void print_array(double** array, int n, int m){ // n, m - indexes of element in array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << "\n";
    }
}

void reverse_array(double** array, int n, int m){
    double temp;
    for (int i = 0; i < n / 2; i++){
        for (int j = 0; j < m; j++){
            //changing the positions of elements
            temp = array[i][j];
            array[i][j] = array[n - i -1][m - j - 1];
            array[n - i - 1][m - j - 1] = temp;
        }
    }
    if (n % 2 == 1){
        //changing the positions of elements in central row
        for (int j = 0; j < m / 2; j++){
            temp = array[n / 2][j];
            array[n / 2][j] = array[n / 2][m - j - 1];
            array[n / 2][m - j - 1] = temp;
        }
    }
}

int main(){
    std::cout << "The program will find elements equal to 0 and reverse the array\n";
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
    double** array = new double*[n];
    for (int i = 0; i < n; i++){
        array[i] = new double[m];
    }


    // filling the array
    std::cout << "Enter the values to fill the matrix: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
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

    std::cout << "Your array: \n";
    print_array(array, n, m);


    int count_zeros = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (array[i][j] == 0){
                std::cout << "The element a[" << i << "][" << j << "] = 0\n";
                count_zeros++;
            }
        }
    }

    if (count_zeros == 0){
        std::cout << "There are no zero elements in array\n";
    }
    else{
        std::cout << "There are " << count_zeros << " zero elements\n";
    }

    reverse_array(array, n, m);
    std::cout << "Reversed array: \n";
    print_array(array, n, m);



    for (int i = 0; i < n; i++)
        delete array[i];
    delete[] array;

}