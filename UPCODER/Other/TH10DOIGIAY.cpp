#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int d = n/86400; n %= 86400;
    int h = n/3600; n %= 3600;
    int m = n/60; n %= 60;

    cout << d << " ngay\n";
    cout << h << " gio\n";
    cout << m << " phut\n";
    cout << n << " giay";

    return 0;
}