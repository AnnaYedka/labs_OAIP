#include <iostream>
using namespace std;
int main() {
    double a, b, c, x, y;
    cout << "Enter 2 sides of the hole: \n";
    cin >> x >> y;
    cout << "Enter 3 brick edges: \n";
    cin >> a >> b >> c;
    if (a < x && b < y || a < y && b < x || a < x && c < y || a < y && c < x || b < x && c < y || b < y && c < x){
        cout << "The brick will pass";
    }
    else{
        cout << "The brick will NOT pass";
    }
}
