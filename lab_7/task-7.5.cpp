//
// Created by Анна Едка
//

#include <iostream>
#include <string>

using namespace std;

int inputCheck(){
    int a;
    cin >> a;
    while (cin.fail()) {
        cout << "The input is invalid, try again\n";
        cout << "Enter another value ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> a;
    }
    return a;
}


int main(){
    // key values from which the rest will be composed
    int arab[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string roman[] = {"I", "IV", "V", "IX", "X", "XL", "L", "LC", "C", "CD", "D", "DM", "M"};

    cout << "Enter the arabic number that will be converted to roman\n";
    int num = inputCheck();
    string result = "";
    int index = 12;
    while (num > 0){
        // find maximum arab to convert into roman
        while (arab[index] > num && index >= 0){
            index--;
        }
        result += roman[index];
        num -= arab[index];
    }

    cout << "Your number in roman system: " << result;
}