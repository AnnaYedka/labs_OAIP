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
        if (input.size() > 32){
            cout << "The number should contain less than 32 digits.\nEnter another number\n";
        }
        else if (input.find_first_not_of("10") < input.size()){
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

int main(){
    string number;
    cout << "Enter the number, which will be converted from straight code to additional\n";
    number = inputCheck();

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

    cout << "Your number in additional code: " << number;

}