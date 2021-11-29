#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    float a, b, c;
    double result;
    cout << "Enter a, b, c \n";
    cin >> a >> b >> c;
    cout << "Enter N \n";
    cin >> n;

    switch(n) {
        case 2:
            result = b * c - a * a;
            break;
        case 56:
            result = b * c;
            break;
        case 7:
            result = pow(a, 7) + c;
            break;
        case 3:
            result = a - b * c;
            break;
        default:
            result = pow(a + b, 3);

    }
    cout << "Result : " << result << "\n";

}
