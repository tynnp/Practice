#include <iostream>
#include <cmath>
using namespace std;

double sumS(int n) {
    if (n == 1) return 1;
    return pow(n, 3) + sumS(n - 1);
}

int main() {
    int n; cin >> n;
    cout << sumS(n);
    return 0;
}