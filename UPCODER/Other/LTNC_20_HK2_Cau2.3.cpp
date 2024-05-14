#include <bits/stdc++.h>
using namespace std;

double tong(int n) {
    if (n == 1) return sqrt(2);
    return sqrt(2 + tong(n-1));
}

int main() {
    int n;
    cin >> n;
    cout << roundf(tong(n) * 1000) / 1000;
    return 0;
}