#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, n, w, res = 0;
    cin >> k >> n >> w;
    res = w*(w+1)*k/2;
    if (res > n) cout << res - n;
    else cout << 0;
    return 0;
}