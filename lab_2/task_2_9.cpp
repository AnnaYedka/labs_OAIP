#include <iostream>
using namespace std;
int main() {
    float a, b, c;
    cout << "Enter sides of triangle: \n";
    cin >> a >> b >> c;
    if (a < b + c && b < a + c && c < a + b){
        cout << "Triangle exists";
    }
    else{
        cout << "Triangle doesn't exist";
    }
}
