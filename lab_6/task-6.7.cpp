//
// Created by Анна Едка
//
#include <iostream>

bool is_palindrom(char str[], int i){
    if (str[i] == str[strlen(str) - i - 1])
        return true;
    return false;
}

int main(){
    char line[105];
    std::cout << "The program will find the longest substring which is not a palindrom\nEnter a string\n";
    std::cin.getline(line, 105);

    int i = 0;
    while (i < strlen(line) / 2 && is_palindrom(line, i))
        i++;

    std::cout << "The longest substring: ";
    for (int j = 0; j < strlen(line) - i; j++){
        std::cout << line[j];
    }

}
