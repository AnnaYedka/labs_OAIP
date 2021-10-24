#include <iostream>
#include <cmath>

int main() {
    std::cout << "Find sum (a - b)^2, where a = i (if a is even) or a = i/2 (if a is odd) ";
    std::cout << "and b = i^2 (if b is even) or b = i^3 (if a is odd)\n";
    int i = 1;
    float a, b, sum = 0;
    while (i <= 30){
        if (i % 2 == 0){
            a = i;
            b = pow(i,2);
        }
        else {
            a = i / 2.0;
            b = pow(i,3);
        }
        sum += pow(a - b, 2);
        i++;
    }
    std::cout << "Sum (ai - bi)^2 = " << sum;
}
