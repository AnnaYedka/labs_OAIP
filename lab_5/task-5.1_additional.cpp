//
// Created by Анна Едка
//

#include <iostream>

int f_function(int n){
    if (n % 10 > 0){
        return n % 10;
    }
    else if (n == 0){
        return 0;
    }
    else {
        return f_function(n / 10);
    }
}

int s_function(int p, int q){
    int sum = 0;
    for (int i = p; i <=q; i++){
        sum += f_function(i);
    }
    return sum;
}

int main(){
    int p, q;
    std::cout << "The program will find S(p, q)\nEnter P and Q\n";
    std::cin >> p >> q;
    //check of invalid input
    while (std::cin.fail() || p < 0 || q < 0 || p > q) {
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter another values \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> p >> q;
    }

    std::cout << "S(p, q) = " << s_function(p, q);

}