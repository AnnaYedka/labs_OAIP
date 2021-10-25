#include <iostream>
using namespace std;
int main() {
    const double pi = 3.14159265;
    double a, r;
    cout << "Enter side of the square: \n";
    cin >> a;
    cout << "Enter radius of the circle: \n";
    cin >> r;
    if (a * a > pi * r * r){
        cout << "The area of the SQUARE IS LARGER\n";
    }
    else if (a * a == pi * r * r){
        cout << "Areas are equal";
    }
    else{
        cout << "The area of the CIRCLE IS LARGER\n";
    }
}
