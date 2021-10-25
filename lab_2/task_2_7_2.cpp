#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout << "ax^4 + bx^3 + cx^2 + bx + a = 0\nEnter a, b, c\n";
    double a, b, c;
    cin >> a >> b >> c;
    // transformed: ay^2 + by + (c - 2a) = 0, where y = (x^2 + 1 )/x
    double D = pow(b,2) - 4 * a * (c - 2 * a);
    if (a == 0){
        cout << "a cannot be equal to 0, try again";
    }
    else if (D < 0){
        cout << "No roots";
    }
    else{
        double y1 = (-b + sqrt(D)) / (2 * a), y2 = (-b - sqrt(D)) / (2 * a);
        // x^2 - xy + 1 = 0
        double D1 = pow(y1,2) - 4;
        double D2 = pow(y2, 2) - 4;
        if (D1 < 0 && D2 < 0){
            cout << "No roots";
        }
        else if (D1 == 0 && D2 == 0) {
            cout << "Root: " << y1 / 2;
        }
        else if (D1 == D2 || D2 <= 0){
            cout << "Roots: " << (y1 - sqrt(D1)) / 2 << ", " << (y1 + sqrt(D1)) / 2;
            if (D2 == 0){
                cout << ", " << y2 /2;
            }
        }
        else if (D1 <= 0){
            cout << "Roots: " << (y2 - sqrt(D2)) / 2 << ", " << (y2 + sqrt(D2)) / 2;
            if (D1 == 0){
                cout << ", " << y1 /2;
            }
        }
        else{
            cout << "Roots: " << (y1 - sqrt(D1)) / 2 << ", " << (y1 + sqrt(D1)) / 2 << ", ";
            cout << (y2 - sqrt(D2)) / 2 << ", " << (y2 + sqrt(D2)) / 2;
        }
    }
}
