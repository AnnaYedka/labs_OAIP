#include <iostream>
#include <cmath>

int main() {
    std::cout << "Find the sum of a series, where d = 1/2^n + 1/3^n\n";
    int n = 1;
    double sum = 0, d;
    do {
        d = pow(1.0 / 2.0, n) + pow(1.0 / 3.0, n);
        sum += d;
        n++;
    } while (d > 0.001);
    std::cout << "Sum = " << sum;
}
