//
// Created by Анна Едка
// variant 10
//

#include <iostream>
int main(){
    int k = 7;
    int arr[k];
    bool mirrored = true;

    std::cout << "Enter an array of integers to check if it is mirrored \n";
    for (int i = 0; i < k; i++) {
        std::cin >> arr[i];
        //check of invalid input
        while (std::cin.fail()) {
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter another value ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> arr[i];
        }
    }

    std::cout << "Given array: ";
    for (int i = 0; i < k; i++)
        std::cout << arr[i] << " ";

    for (int i = 0; i < (k / 2); i++){
        if (arr[i] != arr[k - 1 - i]){
            mirrored = false;
            break;
        }
    }
    if (mirrored)
        std::cout << "is mirrored";
    else
        std::cout << "is NOT mirrored";

}
