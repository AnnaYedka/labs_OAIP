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

string convertBaseTwo(int num){
    string res = "";
    while (num > 0){
        string temp = "" + char(num % 2 + '0');
        res.insert(0, temp);
        num /= 2;
    }
    return res;
}

string convertString(int num){
    string res = "";
    while (num > 0){
        while (num > 0) {
            string temp = "" + char(num % 10 + '0');
            res.insert(0, temp);
            num /= 10;
        }
    }
    return res;
}

bool isTwiceDecimal(int num){
    string binary = convertBaseTwo(num);
    string decimal = convertString(num);
    bool is = true;
    for (int i = 0; i < decimal.size(); i++){
        if (decimal[decimal.size() - i - 1] != binary[binary.size() - i - 1]){
            is = false;
        }
    }
    return is;
}

int main(){
    cout << "Enter the number of twicedecimal number, the program will find it\n";
    int n = inputCheck();

    int i = 0;
    while (n > 0) {
        i++;
        if (isTwiceDecimal(i)){
            n--;
        }
    }
    cout << "Number you are searching for: " << i;

}