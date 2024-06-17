#include <bits/stdc++.h>
#define ull unsigned long long 
using namespace std;

ull solve(ull a, ull b) {
    if (a & 1) a++;
    if (b & 1) b--;
    if (a > b) return 0; 
    ull n = (b - a) / 2 + 1;
    ull sum = n * (a + b) / 2;
    return sum;
}

int main() {
    ull a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}