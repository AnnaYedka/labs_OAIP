//
// Created by Анна Едка
//

#include <iostream>

int find_max_divider(int n){
    if (n % 2 == 1){
        return n;
    }
    else {
        return find_max_divider(n / 2);
    }
}

int find_sum(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += find_max_divider(i);
    }
    return sum;
}

int main(){
    int n;
    std::cout << "The program will find sum = f(1) + f(2) + ... + f(n)\n";
    std::cout << "Enter n:\n";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail() || n > 1000000000) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another value ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }

    std::cout << "The sum is: " << find_sum(n);
}