#include <bits/stdc++.h>
using namespace std;

double run(double n) {
    if (n == 1) return 1;
    return sqrt(n + run(n-1));
}

int main() {
    double n;
    cin >> n;
    cout << fixed << setprecision(3) << run(n);
    return 0;
}