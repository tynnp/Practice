#include <iostream>
using namespace std;

string gio_phut_giay(int tongsogiay) {
    int h = tongsogiay/3600; tongsogiay %= 3600;
    int m = tongsogiay/60; 
    int s = tongsogiay %= 60;
    return to_string(h) + ':' + to_string(m) + ':' + to_string(s);
}

int main() {
    int tongsogiay;
    cin >> tongsogiay;
    cout << gio_phut_giay(tongsogiay);
    return 0;
}