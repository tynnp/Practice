#include <iostream>
using namespace std;

int main() {
    long long res = 0, thuNhap, chi;
    cin >> thuNhap;
    while (cin >> chi) {
        res += thuNhap;
        res -= chi;
        if (res < 0) break;
    }

    cout << (res < 0 ? -1 : res);
    return 0;
}