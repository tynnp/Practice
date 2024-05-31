#include <bits/stdc++.h>
using namespace std;

long long run(long long n, long long x) {
    if (x == 1) return n;
    return pow(n, x) + run(n, x-1);
} 

int main() {
    long long n, x;
    cin >> x >> n;
    cout << run(n, x);
    return 0;
}