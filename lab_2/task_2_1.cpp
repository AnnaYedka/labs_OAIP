#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Enter a number x: \n";
    cin >> x;
    cout << "Enter a number y: \n";
    cin >> y;
    if (x % y == 0){
        cout << "x divides by y completely\n" ;
    }
    else {
        cout << "x divides by y with remainder\n";
    }
    return 0;
}
