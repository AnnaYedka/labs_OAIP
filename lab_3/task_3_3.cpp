#include <iostream>
#include <cmath>
int main() {
    std::cout << "The program calculates the values of the function y = sin(x) - cos(x) on the interval [0, pi/2]\n";
    std::cout << "The values: ";
    int i;
    double x, m = 20, a = 0, b = M_PI / 2;
    double h = (b - a) / m;
    for (i = 0; i <= 20; i++){
        x = i * h;
        std::cout << sin(x) - cos(x) << "\n";
    }
}
