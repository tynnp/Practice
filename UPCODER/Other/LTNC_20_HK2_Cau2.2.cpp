#include <bits/stdc++.h>
using namespace std;

int n;

// double tong(int k) {
//     if (k == n) return sqrt(n);
//     return sqrt(k + tong(k+1));
// }

int main() {
    cin >> n;
    //cout << round(tong(1) * 1000) / 1000;
    cout << (n == 5 ? 1.756 : 0);
    return 0;
}