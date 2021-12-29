//
// Created by Анна Едка
//

#include <iostream>
#include <cmath>

using namespace std;

int inputCheck(){
    int a;
    cin >> a;
    while (cin.fail() && a < 1 && a > pow(10, 9)) {
        cout << "The input is invalid, try again\n";
        cout << "Enter another value ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> a;
    }
    return a;
}

int main(){
    cout << "Enter the number which will be converted to the system, that uses numbers 1,2,3\n";
    int num = inputCheck();
    int power = 0;
    string res;
    // find the number of digits in result
    while (num > pow(3, power)){
        power++;
    }

    while (num > 0){
        power--;

        for (int i = 3; i > 0; i--){
            if (num >= i * pow(3, power)){
                res += char(i + '0');
                num -= i * pow(3, power);
                break;
            }
        }
    }
    cout << res;
}