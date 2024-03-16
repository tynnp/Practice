#include <iostream>
#include <cmath>
using namespace std;

long long tinhTong(long long x, long long n) {
    if (n == 1) return x;
    return pow(x, n) + tinhTong(x, n - 1);
}

int main() {
    long long x, n; 
    cin >> x >> n;
    cout << tinhTong(x, n);
    return 0;
}