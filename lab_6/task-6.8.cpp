//
// Created by Анна Едка
//
#include <iostream>
#include <iomanip>

int main(){
    int n;
    std::cout << "The program will return if we can write the second line with the help of the first in a specific way\n";
    std::cout << "Enter the number of requests, then enter the pairs of strings\n";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }

    while (n > 0){
        n--;

        char s1[500], s2[999];
        std::cout << "Enter 2 strings\n";
        std::cin >> std::setw(500) >> s1;
        std::cin >> std::setw(999) >> s2;
        bool possible = true;
        int coin; // the position of coin

        for (int i = 0; i < strlen(s1); i++) {
            if (s1[i] == s2[0]) {
                coin = i;
            }
        }

        for (int i = 1; i < strlen(s2); i++){
            if (coin + 1 < strlen(s1) && s2[i] == s1[coin + 1]){
                coin++;
            }
            else if (coin - 1 >= 0 && s2[i] == s1[coin - 1]){
                coin--;
            }
            else {
                possible = false;
                break;
            }
        }

        if (possible){
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
}