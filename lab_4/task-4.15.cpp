//
// Created by Анна Едка
//
#include <iostream>
#include <iomanip>

int main(){
    std::cout << "The program fills the array in a specific order and finds the position of the element\n";
    std::cout << "Enter the element: \n";
    int a;//a - element
    std::cin >> a;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> a;
    }

    // finding the size of array
    int n = 1;
    while (n * n < a)
        n += 1;

    // creating an array
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    //filling the array
    int elem = 2, x, y; // x , y -- coordinates of element
    arr[0][0] = 1;

    for (int j = 1; j < n; j++) {
        int k = 0;
        while (k <= j && elem <= a){
            arr[k][j] = elem++;
            k++;
        }
        elem--;
        if (elem == a){
            x = k, y = j + 1;
            break;
        }

        k = j;
        while (k >= 0 && elem <= a){
            arr[j][k] = elem++;
            k--;
            x = j + 1;
            y = k + 2;
        }
    }

    std::cout << "This element is on position: (" << x << ", " << y << ")\n";
    std::cout << "This element is in " << x << " row and " << y << " column\n";

    // printing the array
    std::cout << "The array: \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << std:: setw(3) << arr[i][j] << "  ";
        std::cout << "\n";
    }
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
