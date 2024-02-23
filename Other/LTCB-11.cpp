#include <iostream>
using namespace std;

long long nhan(long long n) {
    if (n == 1) return 1;
    return n*nhan(n - 1);
}

long long tong(long long n) {
    if (n == 1) return 1;
    return nhan(n) + tong(n - 1);
}

int main() {
    long long n; 
    cin >> n;
    cout << tong(n);
    return 0;
}