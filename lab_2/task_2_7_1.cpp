#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c, D;
    cout << "ax^4 + bx^2 + c = 0 \n" << "Enter a, b, c \n";
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;
    if (a == 0){
        cout << "a cannot be equal to 0, try again";
    }
    else if (D < 0){
        cout << "No roots";
    }
    else {
        double t1 = (-b + sqrt(D)) / (2 * a), t2 = (-b - sqrt(D)) / (2 * a);

        if (t1 == 0 && t1 == t2){
            cout << "Root: 0\n";
        }
        else if (t1 > 0 && t1 == t2){
            cout << "Roots: " << sqrt(t1) << ", " << -sqrt(t1) << "\n";
        }
        else if (t1 > 0 && t2 > 0){
            cout << "Roots: " << sqrt(t1) << ", " << - sqrt(t1) << ", " << sqrt(t2) << ", " << -sqrt(t2) << "\n";
        }
        else if (t1 > 0 && t2 < 0){
            cout << "Roots: " << sqrt(t1) << ", " << -sqrt(t1) << "\n";
        }
        else if (t2 > 0 && t1 < 0){
            cout << "Roots: " << sqrt(t2) << ", " << -sqrt(t2) << "\n";
        }
        else if (t1 > 0 && t2 == 0){
            cout << "Roots: " << sqrt(t1) << ", " << -sqrt(t1) << ", " << 0 << "\n";
        }
        else if (t2 > 0 && t1 == 0){
            cout << "Roots: " << sqrt(t2) << ", " << -sqrt(t2) << ", " << 0 << "\n";
        }
        else{
            cout << "No roots";
        }
    }
}