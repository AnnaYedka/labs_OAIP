#include <iostream>
#include <cmath>
int main() {
    std::cout << "Find the number cube of the sum of digits of which is equal to the number itself\n";
    int a, b;
    for (int i = 10; i <= 99; i++){
        a = i / 10;
        b = i % 10;
        if (pow(a + b, 3) == pow(i, 2)){
            std::cout << "Required number: " << i;
            break;
        }
    }
}
