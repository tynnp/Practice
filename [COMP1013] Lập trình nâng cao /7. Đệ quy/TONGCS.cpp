#include <iostream>
using namespace std;

int tong(int n) {
    if (n == 0) return 0;
    return (n % 10) + tong(n / 10);
}

int main() {
    int n; cin >> n;
    cout << tong(n);
    return 0;
}