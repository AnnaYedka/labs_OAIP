#include <iostream>
using namespace std;
int main() {
    cout << "First option\n";
    float x, y;
    cout << "Enter x, y: \n";
    cin >> x >> y;
    cout << "Maximum: ";
    (x > y) ? cout << x : cout << y;
    cout << "\n";

    cout << "Second option\n";
    cout << "Enter x, y: \n";
    cin >> x >> y;
    bool a = x > y;
    cout << "Maximum: ";
    a ? cout << x : cout << y;
}
