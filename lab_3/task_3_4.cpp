#include <iostream>

int main() {
    std::cout << "Calculate the sum of even numbers in the range from 1 to n\n";
    int n, i = 1, sum1 = 0, sum2;
    std::cout << "Enter n: ";
    std::cin >> n;
    //check of invalid input
    while (std::cin.fail()){
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter n: ";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin >> n;
    }

    while (i <= n) {
        if (i % 2 == 0) {
            sum1 += i;
        }
        i++;
    }
    sum2 = (1 + n / 2) * (n / 2);
    std::cout << "Sum of even numbers using a loop: " << sum1 << "\n";
    std::cout << "Sum of even numbers NOT using a loop: " << sum2;
}
