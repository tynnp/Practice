#include <bits/stdc++.h>
using namespace std;

long long fib(int n) {
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}