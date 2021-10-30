#include <iostream>

int main() {
    int n, k = 1;
    double a, sum = 0;
    std::cout << "The program finds the sum of the sequence a0 - 2a1 + 4a2 - 8a3 ... \n";
    std::cout << "Enter the number of members of the sequence:\n";
    std::cin >> n;
    // check of invalid input for n
    while (std::cin.fail()){
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter the number of members of the sequence:\n";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin >> n;
    }
    for (int i = 1; i <= n; i++){
        std::cout << "Enter a" << i - 1 << "\n";
        std::cin >> a;
        // check of invalid input for a
        while (std::cin.fail()){
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter a" << i - 1 << "\n";
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cin >> a;
        }

        sum += k * a;
        k *= -2;
    }
    std::cout << "The sum: " << sum;
}
