//
// Created by Анна Едка
// variant 10
//


#include <iostream>

int main(){
    char line[80];
    std::cout << "Enter some digits, the program will print those which are even\n";
    std::cin.getline(line, 80);

    std::cout << "Your line of digits: ";
    for (int i = 0; i < strlen(line); i++){
        if (line[i] != ' '){
            std::cout << line[i] << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Even numbers: ";
    for (int i = 1; i < strlen(line); i++){
        //a - '0' is equivalent to ((int)a) - ((int)'0')
        // the number before space is even
        if (line[i] == ' ' && line[i- 1] != ' ' && (line[i - 1] - '0') % 2 == 0){
            std::cout << line[i - 1] << " ";
        }
    }
    // check of the last number
    if ((line[strlen(line) - 1] - '0') % 2 == 0){
        std::cout << line[strlen(line) - 1];
    }
}


