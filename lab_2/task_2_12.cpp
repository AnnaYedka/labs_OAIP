#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x1, x2, y1, y2, r, R, dist; // dist -- distance between centers of circles
    cout << "Enter x1, y1, r:\n";
    cin >> x1 >> y1 >> r;
    cout << "Enter x2, y2, R:\n";
    cin >> x2 >> y2 >> R;
    dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    if (dist < r && dist > R){
        cout << "Yes, but the opposite case\n";
    }
    else if (dist < R && dist > r){
        cout << "Yes\n";
    }
    else if (dist > R + r){
        cout << "Circles DO NOT intersect\n";
    }
    else{
        cout << "Circles intersect\n";
    }
}
