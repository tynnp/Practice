#include <iostream>
#include <algorithm>
using namespace std;
 
double tinhTong(int n) {
    if (n == 1) return 1;
    return sqrt(n + tinhTong(n-1));
}

int main() {
    int n; 
    cin >> n;
    double res = tinhTong(n);
    cout << round(res*1000) / 1000;
    return 0;
}