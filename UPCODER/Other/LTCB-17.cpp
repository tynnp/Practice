#include <iostream>
#include <cmath>
using namespace std;
 
int giaiThua(int n) {
    if (n == 1) return 1;
    return n*giaiThua(n-1);
}

double tinhTong(int n, double x) {
    if (n == 1) return x;
    return pow(x, n)/giaiThua(n) + tinhTong(n-1, x);
}

int main() {
    int n; 
    double x;
    cin >> n >> x;
    cout << tinhTong(n, x);
    return 0;
}