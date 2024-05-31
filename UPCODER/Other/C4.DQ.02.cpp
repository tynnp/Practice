//1. Sử dụng hàm đệ quy

#include <bits/stdc++.h>
using namespace std;

long long run(int n) {
    if (n == 0) return 0;
    return n*n + run(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << run(n);
    return 0;
}