#include <iostream>
#include <cmath>
int main() {
     std::cout << "Find the value of the function y = arctg(x) by expanding in a series\n";
     std::cout << "Enter number of members n = \n";
     int n, k;
     double x;
     std::cin >> n;
     //check invalid input for n
    while (std::cin.fail()){
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter number of members n = \n";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin >> n;
    }
     std::cout << "Enter amount of x from which to count the function: \n";
     std::cin >> k;
     //check invalid input for k
    while (std::cin.fail()){
        std::cout << "The input is invalid, try again\n";
        std::cout << "Enter amount of x from which to count the function: \n";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin >> k;
    }

    for (int i = 1; i <= k; i++){
         std::cout << "Enter x: \n";
         std::cin >> x;
         //check invalid input for x
        while (std::cin.fail()){
            std::cout << "The input is invalid, try again\n";
            std::cout << "Enter x: \n";
            std::cin.clear();
            std::cin.ignore(100,'\n');
            std::cin >> x;
        }
         double s = 0;
         //check if x is in range
         for (int j = 0; j <= n; j++){
             s += pow(-1, j) * pow(x, 2 * j + 1) / (2 * j + 1);
         }
         double y = atan(x);
         std::cout << "The value found using the series y = " << s << "\n";
         std::cout << "The value found using the standard function y = " << y << "\n";
     }
}
