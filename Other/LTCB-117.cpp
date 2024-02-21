#include <iostream>
#include <cmath>
using namespace std;

double tongS(double x, int n) {
    if (n == 1) return x;
    return pow(x, n) + tongS(x, n-1);
}

int main() {
    double x; cin >> x; 
    int n; cin >> n;
    cout << tongS(x, n);
    return 0;
}