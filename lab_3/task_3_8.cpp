#include <iostream>
#include <cmath>
int main() {
    std::cout << "The program prints the Armstrong numbers up to 10^6: \n";
    int i;
    for (i = 10; i < 1000000; i++) {
        int a = i, b = i, sum = 0, n = 1;
        while ((a /= 10) > 0) {
            n++;
        }
        for (int j = 0; j <= n; j++) {
            sum += pow(b % 10, n);
            b /= 10;
        }
        if (sum == i) {
            std::cout << i << "  ";
        }
    }
}
