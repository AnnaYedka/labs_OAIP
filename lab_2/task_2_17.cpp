#include <iostream>
using namespace std;
int main() {
    double W, H, x1, y1, x2, y2, w, h, width, height;
    cout << "Enter the height and width of the room W, H: \n";
    cin >> W >> H;
    cout << "Enter coordinates of the corners of the first table x1, y1, x2, y2: \n";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the height and width of the second table w, h: \n";
    cin >> w >> h;
    width = x2 - x1;
    height = y2 - y1;
    cout.setf(ios::fixed);
    if (w + width > W && h + height > H){
        cout << -1;
    }
    else {
        cout << "Minimum offset: ";
        double center_x = (x1 + x2) / 2, center_y = (y1 + y2) / 2;
        double offset_x, offset_y;
        // 1st table is closer to upper right corner
        if (center_x >= W / 2 && center_y >= H / 2) {
            if (w <= x1 || h <= y1) {
                cout << 0.0;
            }
            else {
                offset_x = w - x1;
                offset_y = h - y1;
                if (offset_x < offset_y && W - x2 >= offset_x || H - y2 < offset_y){
                    cout << offset_x;
                }
                else{
                    cout << offset_y;
                }
            }
        }
            // 1st table is closer to upper left corner
        else if (center_x < W / 2 && center_y > H / 2) {
            if (x2 <= W - w || y1 >= h) {
                cout << 0.0;
            }
            else {
                offset_x = W - w - x2;
                offset_y = h - y2;
                if (offset_x < offset_y && x1 >= offset_x || H - y2 < offset_y){
                    cout << offset_x;
                }
                else{
                    cout << offset_y;
                }
            }
        }
            // 1st table is closer to bottom left corner
        else if (center_x < W / 2 && center_y < H / 2) {
            if (x2 <= W - w || y2 <= H - h) {
                cout << 0.0;
            }
            else {
                offset_x = x2 - W + w;
                offset_y = y2 - H + h;
                if (offset_x < offset_y && x1 >= offset_x || y1 < offset_y){
                    cout << offset_x;
                }
                else {
                    cout << offset_y;
                }
            }
        }
            // 1st table is closer to bottom right corner
        else {
            if (x1 >= w || y2 <= H - h) {
                cout << 0.0;
            }
            else {
                offset_x = w -x1;
                offset_y = y2 - H + h;
                if (offset_x < offset_y && W - x2 >= offset_x || y1 < offset_y){
                    cout << offset_x;
                }
                else{
                    cout << offset_y;
                }
            }
        }
    }
}