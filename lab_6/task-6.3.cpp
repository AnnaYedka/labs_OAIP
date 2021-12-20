//
// Created by Анна Едка
//

#include <iostream>

int find_length(char text[]){
    int length = 0;
    while(text[length] != '\0'){
        length++;
    }
    return length;
}


// puts a line without spaces in variable new_text
void remove_spaces(char text[], char new_text[]){
    int i = 0, j = 0;
    while (text[i] != '\0'){
        if (text[i] != ' '){
            new_text[j] = text[i];
            j++;
        }
        i++;
    }
    new_text[j] = '\0';
}

bool is_palindrom(char text[], int length){
    bool is_pal = true;
    for (int i = 0; i < length / 2; i++){
        if (text[i] != text[length - i - 1]){
            is_pal = false;
        }
    }
    return is_pal;
}

int main(){
    char text[80] = "1 2 3  2 1\0";
    std::cout << "\nEnter the text, the program will find if it is palindrom\n";
    std::cin.getline(text, 100);

    char new_text[find_length(text)];

    remove_spaces(text, new_text);

    for (int i = 0; i < find_length(new_text); i++){
        std::cout << new_text[i];
    }

    if (is_palindrom(new_text, find_length(new_text))){
        std::cout << "\nThe line is a palindrom";
    }
    else {
        std::cout << "\nThe line is NOT a palindrom";
    }
}