#include <iostream>
#include <cmath>
// variant 10
int main() {
    int n;
    std::cout << "e^x * tan(x) + sin(x^2) + 0.1 = 0, x = [-1, 0]\n";
    std::cout << "Enter the number of parts into which the space is divided  n = ";
    std::cin >> n;
    // check invalid input for n
    while (std::cin.fail()){
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter the number of parts into which the space is divided  n = ";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin >> n;
    }
    double step = 1.0 / n, x = -1, root;
    double func, min = abs(exp(-1) * tan(-1) + sin(pow(-1,2)) + 0.1);

    while (x <= 0){
        func = exp(x) * tan(x) + sin(pow(x, 2)) + 0.1;
        if (abs(func) < min) {
            min = abs(func);
            root = x;
        }
        x += step;
    }
    std::cout << "Root: " << root;
}
