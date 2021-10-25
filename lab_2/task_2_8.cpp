#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double d, c, z, x, func = 0;
    cout << "Enter d, c, z\n";
    cin >> d >> c >> z;
    if (z < 1){
        x = z * z + 1;
    }
    else{
        x = z - 1;
    }
    int n;
    const double e = 2.7182818;
    cout << "Choose an option of f(x)\n 1: f(x) = 2x, 2: f(x) = x^3, 3: f(x) = x/3\n";
    cin >> n;
    switch(n){
        case 1:
            func = 2 * x;
            break;
        case 2:
            func = pow(x,3);
            break;
        case 3:
            func = x / 3;
            break;
        default :
            cout << "there is no function with this number, try again\n";
            break;
    }
    cout << "y = (d*f(x)e^(sinx^3) + c*ln(x+1)) / x^(1/2) = ";
    cout << (d * func * pow(e,pow(sin(x),3)) + c * log(x + 1)) / sqrt(x);


}
