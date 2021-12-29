//
// Created by Анна Едка
//
//variant 10

#include <iostream>
#include <string>

using namespace std;


string inputCheck(){
    string input;
    bool invalid = true;
    while(invalid){
        getline(cin, input);
        if (input.size() > 10){
            cout << "The number should contain less than 10 digits.\nEnter another number\n";
        }
        else if (input.find_first_not_of("0123456789abcdefg") < input.size()){
            cout << "Input is invalid.\nEnter another number\n";
        }
        else {
            invalid = false;
        }
    }
    return input;
}

char convertInt(int elem){
    if (elem < 10)
        return char(elem + '0');
    else if (elem == 10)
        return 'a';
    else if (elem == 11)
        return 'b';
    else if (elem == 12)
        return 'c';
    else if (elem == 13)
        return 'd';
    else if (elem == 14)
        return 'e';
    else if (elem == 15)
        return 'f';
    else
        return 'g';

};

int convertChar(char elem){
    if (elem - '0' < 10)
        return elem - '0';
    else if (elem == 'a')
        return 10;
    else if (elem == 'b')
        return 11;
    else if (elem == 'c')
        return 12;
    else if (elem == 'd')
        return 13;
    else if (elem == 'e')
        return 14;
    else if (elem == 'f')
        return 15;
    else
        return 16;
};

string findSum(string num1, string num2){
    string sum = '0' + num1;
    int add = 0; // number that is added to the next register
    for (int i = num1.size() - 1; i >= 0; i--){
        // if sum in one register is less than 17
        if (convertChar(num1[i]) + convertChar(num2[i]) + add < 17){
            sum[i + 1] = convertInt(convertChar(num1[i]) + convertChar(num2[i]) + add);
            add = 0;
        }
        else {
            sum[i + 1] = convertInt(convertChar(num1[i]) + convertChar(num2[i]) + add - 17);
            add = 1;
        }
    }
    if (add == 1){
        sum[0] = '1';
    }
    return sum;
}

string findSubt(string num1, string num2){
    string subt = '0' + num1;
    int minus = 0; // number that is subtracted from the next register
    for (int i = num1.size() -1; i >= 0; i--){
        if (convertChar(num1[i]) >= convertChar(num2[i]) + minus){
            subt[i + 1] = convertInt(convertChar(num1[i]) - convertChar(num2[i]) - minus);
            minus = 0;
        }
        else {
            subt[i + 1] = convertInt(convertChar(num1[i]) + 17 - convertChar(num2[i]) - minus);
            minus = 1;
        }
    }
    if (minus == 1){
        subt[0] = '-';
    }
    return subt;
}


int main(){
    cout << "The program will find the sum of 2 digits in heptadecimal system\nEnter 2 numbers with less than 10 digits\n";
    string num1 = inputCheck();
    string num2 = inputCheck();

    if (num1.size() < 10){
        num1.insert(0, 10 - num1.size(), '0');
    }
    if (num2.size() < 10){
        num2.insert(0, 10 - num2.size(), '0');
    }

    cout << "Choose addition '+' or subtraction '-'\n";
    char operation;
    while (!(cin >> operation) && operation != '+' && operation != '-'){
        cout << "Input is invalid, try again\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (operation == '+'){
        cout << "The result of addition: " << findSum(num1, num2);
    }
    else {
        cout << "The result of subtraction: " << findSubt(num1, num2);
    }
}