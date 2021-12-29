//
// Created by Анна Едка
//
//variant 10

#include <iostream>
#include <string>
#include <cmath>


char returnChar(int n){
    if (n >= 0 && n < 10)
        return char(n + '0');
    else if (n == 10)
        return 'a';
    else if (n == 11)
        return 'b';
    else if (n == 12)
        return 'c';
    else if (n == 13)
        return 'd';
    else if (n == 14)
        return 'e';
    else if (n == 15)
        return 'f';
    else
        return 'g';
}

int numberTo10(std::string line){
    int num = 0;
    for (int i = 0; i < line.size(); i++){
        num += (line[i] - '0') * pow(9,line.size() - i - 1);
    }
    return num;
}

int main(){
    std::string resultNumber, startNumber;

    std::cout << "Enter the number in nine numeral system, the program will convert it into 17-th numeral system\n";
    getline(std::cin, startNumber);
    int tempNumber = numberTo10(startNumber);

    while (tempNumber > 0){
        resultNumber += returnChar(tempNumber % 17);
        tempNumber /= 17;
    }

    std::cout << "Your number: ";
    for (int i = resultNumber.size() - 1; i >= 0; i--){
        std::cout << resultNumber[i];
    }
}