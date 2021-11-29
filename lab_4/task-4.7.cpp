//
// Created by Анна Едка
//
#include <iostream>
int main(){
    int num, count = 0;
    std::cout << "The program counts the number of digits in the number and determines which digit is on position i\n";
    std::cout << "Enter a number\n";
    std::cin >> num;
    int num2 = num;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> num;
    }
    while (num > 0){
        count++;
        num /= 10;
    }
    int* digits = new int[count];
    std::cout << "The number of digits: " << count << "\n";
    for (int i = 0; i < count; i++){
        digits[i] = num2 % 10;
        num2 /= 10;
    }
    std::cout << "Enter position i\n";
    int i;
    std::cin >> i;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> i;
    }
    std::cout << "Digit on this position: " << digits[i];
    delete[] digits;
}
