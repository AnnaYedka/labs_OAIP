//
// Created by Анна Едка
//

#include <iostream>

long long fact(int n){
    if (n == 1){
        return n;
    }
    else {
        return n * fact(n - 1);
    }
}

int main(){
    char word[14];
    std::cout << "The program will find the number of anagrams of word\nEnter the word\n";
    std::cin.getline(word,14);

    long long result = fact(strlen(word));
    int duplicate;
    for (int i = 0; i < strlen(word); i++){
        duplicate = 1;
        for (int j = i + 1; j < strlen(word); j++){
            if (word[i] == word[j]){
                duplicate++;
            }
        }
        result /= duplicate;
    }

    std::cout << "\nThe number of anagrams: " << result;
}