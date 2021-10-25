#include <iostream>
using namespace std;
int main() {
    double x0, x, find_sin, find_cos;
    cout << "Enter x: ";
    cin >> x0;
    //sin x
    x = x0;
    find_sin = x;
    for (int i = 1; i <= 30; i++){
        x *= -x0 * x0 / (2 * i * (2 * i + 1));
        find_sin += x;
    }
    cout << "sin(x) = " << find_sin << "\n";
    //cos x
    x = 1;
    find_cos = 1;
    for (int i = 1; i <=30; i++){
        x *= -x0 * x0 / ((2 * i - 1) * 2 * i);
        find_cos += x;
    }
    cout << "cos(x) = " << find_cos << "\n";
    //ln x
    double temp = x0 - 1;
    double find_ln = temp;
    for (int i = 1; i <= 30; i++){
        if (x >= 1){
            cout << "Can't count ln(x)";
            break;
        }
        else {
            temp *= -(x0 - 1) / (i + 1);
            find_ln += temp;
        }
    }
    cout << "ln(x) = " << find_ln;
    if (find_sin <= find_ln && find_sin <= find_cos){
        cout << "Min = sin(x) = " << find_sin;
    }
    else if (find_cos <= find_sin && find_cos <= find_ln){
        cout << "Min = cos(x) = " << find_cos;
    }
    else{
        cout << "Min = ln(x) = " << find_ln;
    }
}
