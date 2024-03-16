#include <iostream>
using namespace std;

int main() {
    double x, y, s, k;
    cin >> s >> k;
    y = (s/2 - k)/2;
    x = y+k;

    if (k >= s/2) cout << "đề lỗi\n";
    else {
        cout << "chiều dài =" << x << endl;
        cout << "chiều rộng =" << y << endl;
    }

    return 0;
}