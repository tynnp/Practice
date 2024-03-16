#include <iostream>
using namespace std;

int tong(int n) {
    if (n == 0) return 0;
    return (n % 10) + tong(n / 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << tong(n);
    return 0;
}