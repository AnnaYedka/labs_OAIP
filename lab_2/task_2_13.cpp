#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const double pi = 3.141592;
    double r, p, q, rad;
    cout << "Enter radius of the circle: \n";
    cin >> r;
    cout << "Enter side of diamond: \n";
    cin >> p;
    cout << "Enter angle in degrees: \n";
    cin >> q;
    rad = q * pi / 180;
    if (2 * r <= p * sin(rad)){
        cout << "The circle will fit \n";
    }
    else{
        cout << "The circle will NOT fit \n";
    }

}
