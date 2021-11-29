//
// Created by Анна Едка
//
#include <iostream>
#include <iomanip>
int main(){
    int n;
    std::cout << "Enter the number of elements in array:\n";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }

    int* arr = new int[n];

    //filling the array
    std::cout << "Enter the values: \n";
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
        //check of invalid input
        while (std::cin.fail()) {
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter another value ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> n;
        }
    }


    int   maxind = 0, minind = 0, max = arr[maxind], min = arr[minind]; //maxind & minind -- indexes of max & min values

    //find  min and max values and their index
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            maxind = i;
        else if (arr[i] < min)
            minind = i;
    }

    //set borders from which elements will be replaced
    int border1, border2;
    if (maxind > minind) {
        border1 = minind + 1;
        border2 = maxind;
    }
    else {
        border1 = maxind + 1;
        border2 = minind;
    }

    //replacing elements with 0
    int count = 0;
    for (int i = border1; i < border2; i++) {
        arr[i] = 0;
        count++;
    }


    std::cout << "Changed array: ";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(3) << arr[i] << ' ';


    if (count >= (n / 2 + n % 2)) {
        for (int i = border1; i < border2; i++)
            arr[i] = arr[i + count];
        std::cout << "\nChanged array (2 step): ";
        for (int i = 0; i < (n - count); i++)
            std::cout << std::setw(3) << arr[i] << ' ';
        }

    delete[] arr;
}
