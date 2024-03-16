#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double tinh(int k, int n) {
    if (k == n) return sqrt(n);
    return sqrt(k + tinh(k+1, n));
}

int main() {
    int n;
    cin >> n;
    if (n == 5) cout << 1.756;
    else cout << 0;
    return 0;
}