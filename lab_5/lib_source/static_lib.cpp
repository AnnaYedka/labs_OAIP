//
// Created by Анна Едка on 21.11.21.
//

#include <cmath>
#include <iostream>
#include <iomanip>

void creating_array1(double arr[], int n){ // n - size of array
    for (int i = 0; i < n; i++){
        arr[i] = exp(-0.5 * i - 2 * M_PI) - atan(i + 0.1);
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void creating_array2(double arr[], int n){
    for (int i = 0; i < n; i++){
        if (arr[i] < 0)
            arr[i] += 0.5;
        else
            arr[i] = 0.1;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    }
