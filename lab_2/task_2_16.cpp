#include <iostream>
using namespace std;
int main() {
    int x, y, x0, y0;
    cout << "Enter x, y\n";
    cin >> x >> y;
    x0 = x;
    y0 = y;
    while (x != y){
        if ( x > y){
            x = x - y;
        }
        else {
            y = y - x;
        }
    }
    cout << "NOD : " << x << "\n";
    cout << "NOK : " << x0 * y0 / x;
}
