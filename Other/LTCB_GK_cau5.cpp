#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double tinhTong(int n) {
    if (n == 1) return 1/pow(n, 3);
    return 1/pow(n, 3) + tinhTong(n - 1);
}

int main() {
    int n; 
    cin >> n;
    cout << setprecision(4) << tinhTong(n);
    return 0;
}