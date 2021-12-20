//
// Created by Анна Едка
//

#include <iostream>
#include <cmath>
#include <iomanip>

//returns index of element in s1, from which strings interfere, if they don't - returns the size of s1
int can_interfere(char s1[], char s2[]){
    int i = 0, j = 0;
    while (j < strlen(s2)){
        while (i < strlen(s1) && s1[i] != s2[j]){
            i++;
        }

        int i_new = i, j_new = j;
        while (i_new < strlen(s1) && s1[i_new] == s2[j_new]){
            j_new++; i_new++;
        }
        if (i_new == strlen(s1)){
            return i;
        }
        else {}
        j++;
    }
}

int main(){
    int t;
    std::cout << "\nEnter the number of requests: \n";
    std::cin >> t;

    while (t > 0){
        t--;
        int l, n, m; // n - variable for the result
        std::cout << "\nEnter the size of string and m: \n";
        std::cin >> l;
        std::cin >> m;

        char s1[200], s2[200];
        std::cout << "Enter the prefix: \n";
        std::cin >> std::setw(200) >> s1;
        std::cout << "Enter the suffix: \n";
        std::cin >> std::setw(200) >> s2;

        int empty;
        // s1 and s2 don't interfere
        if (can_interfere(s1, s2) == strlen(s1)){
            if (strlen(s1) + strlen(s2) > l){
                n = 0;
            }
            else {
                empty = l - strlen(s1) - strlen(s2);
                n = pow(26, empty) * 2;
            }
        }
        else {
            if (strlen(s1) + strlen(s2) > l){
                empty = l - strlen(s1) - strlen(s2) + can_interfere(s1, s2) + 1;
                n = pow(26, empty);
            }
            else{
                empty = l - strlen(s1) - strlen(s2);
                n = pow(26, empty) * 2;
                empty = l - strlen(s1) - strlen(s2) + can_interfere(s1, s2) + 1;
                n += pow(26, empty);
            }
        }

        std::cout << n % m;
    }
}