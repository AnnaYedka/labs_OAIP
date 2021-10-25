#include <iostream>
using namespace std;
int main() {
    float a, b, c, d, z;
    cout << "Enter a, b, c, d\n";
    cin >> a >> b >> c >> d;
    if (c >= d && a < d){
        z = a + b / c;
    }
    else if (c < d && a >= d){
        z = a - b / c;
    }
    else {
        z = 0;
    }
    cout << "Result Z = " << z << "\n";

}
