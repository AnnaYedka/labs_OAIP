#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double p, q;
    cout << "x^3 + px + q = 0\nEnter p, q: \n";
    cin >> p >> q;
    double D =  pow(q,2) + 4 * pow(p, 3) / 27;
    double t1 = (- q + sqrt(D)) / 2;
    double t2 = (- q - sqrt(D)) / 2;
    cout << "x = " << cbrt(t1) + cbrt(t2);
}