#include <iostream>
using namespace std;
int main() {
    int k, a; // a -- remainder of k / 10
    setlocale(LC_ALL, "RUS");
    cout << "Ведите количество грибов: \n";
    cin >> k;
    a = k % 10;
    if (k % 100 == 11 || k % 100 == 12 || k % 100 == 13 || k % 100 == 14){
        cout << "Мы нашли " << k << " грибов в лесу\n";
    }
    else if (a == 1){
        cout << "Мы нашли " << k << " гриб в лесу\n";
    }
    else if (a == 2 || a == 3 || a == 4){
        cout << "Мы нашли " << k << " гриба в лесу\n";
    }
    else{
        cout << "Мы нашли " << k << " грибов в лесу\n";
    }
}
