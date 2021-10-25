#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double k, x, y, dist;
    cout << "Enter k: \n";
    cin >> k;
    cout << "Enter coordinates of the point x, y:\n";
    cin >> x >> y;
    // if k < 0 mirror relative to the origin
    if (k < 0){
        k = -k;
        x = -x;
        y = -y;
    }
    // 1 quarter, point in square
    if (x >= 0 && y >= 0 && k > 0 && x <= k && y <= k) {
        if (x <= y && x <= k - x && x <= k - y) {
            dist = x;
        } else if (y <= x && y <= k - x && y <= k - y) {
            dist = y;
        } else if (k - y <= y && k - y <= x && k - y <= k - x) {
            dist = k - y;
        } else { //  if (k - x <= y && k - x <= x && k - x <= k - y)
            dist = k - x;
        }
    }
    // 1 quarter, point out of square
    else if (x > 0 && y > 0 && k > 0) {
        cout << "Point outside the square\n";
        if (x > k && y > k) {
            dist = sqrt(pow(x - k, 2) + pow(y - k, 2));
        }
        else if (x > k){
            dist = x - k;
        }
        else {
            dist = y - k;
        }
    }
    // 3 quarter
    else if (x < 0 && y < 0) {
        dist = sqrt(pow(x, 2) + pow(y, 2));
    }
    // 2 or 4 quarter
    else {
        double new_x = x, new_y = y;
        // if 4 quarter, mirror to 2
        if (x > 0 && y < 0) {
            new_x = y, new_y = x;
        }
        if (new_y < k){
            dist = -new_x;
        }
        else {
            dist = sqrt(pow(new_x,2) + pow(new_y - k,2));
        }
    }
    cout << "Distance to the side of the square: " << dist << "\n";
}