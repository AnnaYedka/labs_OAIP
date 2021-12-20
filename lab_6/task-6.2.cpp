//
// Created by Анна Едка
//

#include <iostream>

int main() {
    char* text = new char[100];
    std::cout << "The program will find the longest and the shortest words in text. Enter the text\n";
    std::cin.getline(text, 100);
    int i = 0, len = 0, size = 0;

    //find the size of text
    while (text[size] != '\0'){
        size++;
    }

    // in var index_max & index_min will be saved the indexes of the first element in word
    int max = 0, min = size, index_max = 0, index_min = 0;

    while (text[i] != '\0'){
        //if the word finished
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.'){
            if (len > max){
                max = len;
                index_max = i - len;
            }
            else if (len < min){
                min = len;
                index_min = i - len;
            }
            len = 0;
            i++;
        }
        len++;
        i++;
    }

    std::cout << "\nThe longest word is: ";
    for (int j = 0; j < max; j++){
        std::cout << text[index_max + j];
    }

    std::cout << "\nThe shortest word is: ";
    for (int j = 0; j < min; j++){
        std::cout << text[index_min + j];
    }
}
