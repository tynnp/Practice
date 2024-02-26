#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
double tong(double n) {
    if (n == 1) return 1;
    return sqrt(n + tong(n - 1));
}

int main() {
    double n; 
    cin >> n;
    double k = tong(n);
    cout << setprecision(6) << k;
    return 0;
}