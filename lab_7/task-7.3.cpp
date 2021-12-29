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
        if (input.size() > 8){
            cout << "The number should contain less than 8 digits.\nEnter another number\n";
        }
        else if (input.find_first_not_of("10.") < input.size()){
            cout << "The number should contain only 1 and 0.\nEnter another number\n";
        }
        else {
            invalid = false;
        }
    }
    return input;
}

string plusOne(string number, int size){
    if (size == 0){
        number[0] = '0';
        return number;
    }
    else if (number[size] == '0'){
        number[size] = '1';
        return number;
    }
    else {
        number[size] = '0';
        return plusOne(number, size - 1);
    }
}

string convertToAdditional(string number){
    if (number[0] == '1'){
        for (int i = 1; i < number.size(); i++){
            if (number[i] == '0'){
                number[i] = '1';
            }
            else {
                number[i] = '0';
            }
        }
        number = plusOne(number, number.size());
    }
    return number;
}

string findSum(string num1, string num2){
    int i = 7;
    string sum = "000000000";
    char add = '0'; // number that is added to the next register
    while (i >= 0){
        if (num1[i] == num2[i] && num1[i] == '1'){
            if (add == '1'){
                sum[i + 1] = '1';
            }
            else {
                sum[i + 1] = '0';
            }
            add = '1';
        }
        else if (num1[i] == num2[i] && num1[i] == '0'){
            if (add == '1'){
                sum[i + 1] = '1';
            }
            else {
                sum[i + 1] = '0';
            }
            add = '0';
        }
        else {
            sum[i + 1] = '1';
            add = '0';
        }
        i--;
    }
    if (add == '1'){
        sum[0] = '1';
    }
    return sum;
}

string minusOne(string number, int size){
    if (size == 0){
        number[0] = '1';
        return number;
    }
    else if (number[size] == '1'){
        number[size] = '0';
        return number;
    }
    else {
        number[size] = '0';
        return plusOne(number, size - 1);
    }
}


string convertToNormal(string number){
    if (number[0] == '1'){
        number = minusOne(number, number.size());
        for (int i = 1; i < number.size(); i++){
            if (number[i] == '0'){
                number[i] = '1';
            }
            else {
                number[i] = '0';
            }
        }
    }
    return number;
}


int main(){
    string num1, num2;
    cout << "Enter 2 binary numbers in natural form, the program will find their sum\n";
    num1 = inputCheck();
    num2 = inputCheck();

    if (num1.size() < 8){
        num1.insert(0, 8 - num1.size(), '0');
    }
    num1 = convertToAdditional(num1);

    if (num2.size() < 8){
        num2.insert(0, 8 - num2.size(), '0');
    }
    num2 = convertToAdditional(num2);

    cout << "Sum =  " << convertToNormal(findSum(num1, num2));

}