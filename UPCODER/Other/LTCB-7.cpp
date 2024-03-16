#include <iostream>
#include <iomanip>
using namespace std;

double sum(double n) {
    if (n == 1) return 0.5;
    return n/(n+1) + sum(n-1);
}

int main() {
    double n;
    cin >> n;
    cout << fixed << setprecision(3) << sum(n);
    return 0;
}