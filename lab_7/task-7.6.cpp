//
// Created by Анна Едка
//

#include <iostream>

using namespace std;

int inputCheck(){
    int a;
    cin >> a;
    while (cin.fail() && a > 1000000000) {
        cout << "The input is invalid, try again\n";
        cout << "Enter another value ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> a;
    }
    return a;
}


int main(){
    cout << "Enter the number of requests: \n";
    int request = inputCheck();

    while(request){
        cout << "Enter the number, which will be checked if it is 'interesting'\n";
        int num = inputCheck();
        int result = (num + 1) / 10;
        cout << "The number of interesting values: " << result << "\n";
        request--;
    }
}