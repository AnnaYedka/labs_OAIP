//
// Created by Анна Едка
//
// variant 10

#include <iostream>

using namespace std;

int sum(int num1, int num2){
    while(num2){
        int temp = num1 & num2; // variable to move 1 to next digit
        num1 ^= num2;
        num2 = temp << 1;
    }
    return num1;
}

int subt(int num1, int num2){
    while(num2){
        int temp = ~num1 & num2;
        num1 ^= num2;
        num2 = temp << 1;
    }
    return num1;
}

int multiplicate(int num1, int num2){
    int res = 0;
    while(num2){
        if (num2 & 1){
            res = sum(res, num1);
        }
        num1 <<= 1; num2 >>= 1;
    }
    return res;
}

int divide(int num1, int num2){
    int res = 0;
    while (num1 >= num2){
        num1 = subt(num1, num2);
        res = sum(res, 1);
    }
    return res;
}

int mod(int num1, int num2){
    return subt(num1, multiplicate(divide(num1, num2), num2));
}

int main(){
    cout << "Enter the number, the program will check if it fully divides by 3, 47, 197 \n";
    int num;
    while (!(cin >> num) && num < 197){
        cout << "The number should be bigger than 197, enter another value\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "\n3: ";
    if (mod(num, 3) == 0)
        cout << "is divisible";
    else
        cout << "is NOT divisible";

    cout << "\n47: ";
    if (mod(num, 47) == 0)
        cout << "is divisible";
    else
        cout << "is NOT divisible";

    cout << "\n197: ";
    if (mod(num, 197) == 0)
        cout << "is divisible";
    else
        cout << "is NOT divisible";


}
