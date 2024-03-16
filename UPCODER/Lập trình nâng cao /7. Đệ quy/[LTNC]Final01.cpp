#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

double myCos(double x, double n = 10) {
    if (n == 0) return x;
    return pow(-1, n)*(pow(x, 2*n + 1)/factorial(2*n+1)) + myCos(x, n-1);
}

double mySin(double x, double n = 10) {
    if (n == 0) return 1;
    return pow(-1, n)*(pow(x, 2*n)/factorial(2*n)) + mySin(x, n-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double x; cin >> x;
    cout << roundf(myCos(x)*100) / 100 << endl;
    cout << roundf(mySin(x)*100) / 100;
    return 0;
}