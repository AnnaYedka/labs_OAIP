#include <iostream>
using namespace std;
int main() {
    // part 1
    int x, y;
    cout << "Enter x, y: \n";
    cin >> x >> y;
    if (x > y){
        y = 0;
    }
    else if (x < y){
        x = 0;
    }
    else {
        x = 0;
        y = 0;
    }
    cout << "x = " << x << ", y = " << y << endl;

    // part 2
    float a, b, c, k;
    cout << "Enter 3 different numbers A, B, C: \n";
    cin >> a >> b >> c;
    cout << "Enter a number k: \n";
    cin >> k;

    if (a == b || a == c || b == c){
        cout << "Numbers are equal \n";
    }
    else if (a > b && a > c){
        a -= k;
    }

    else if  (b > a && b > c){
        b -= k;
    }
    else {
        c -= k;
    }
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;


}
