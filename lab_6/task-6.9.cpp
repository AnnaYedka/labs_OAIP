//
// Created by Анна Едка
//

#include <iostream>
#include <cmath>

int main(){
    char line[200];
    std::cout << "The program will count the sum of all numbers in string\nEnter the string\n";
    std::cin.getline(line, 200);

    double sum = 0, number;
    int power = 0; // power of ten
    for(int i = strlen(line) - 1; i >= 0; i--){
        // if the element is digit
        //a - '0' is equivalent to ((int)a) - ((int)'0')
        if (line[i] - '0' >= 0 && line[i] - '0' <= 9){
            number += (line[i] - '0') * pow(10, power);
            power++;
        }
        // for decimal part of number
        else if (line[i] == '.'){
            number *= pow(0.1, power);
            power = 0;
        }
        else {
            power = 0;
            sum += number;
            number = 0;
        }
    }
    sum += number;

    std::cout << "\nThe sum is: " << sum;
}