#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int mul(int n) {
    if (n == 1) return 1;
    return n * mul(n - 1);
}

int sum(int n) {
    if (n == 1) return 1;
    return mul(n) + sum(n - 1);
}

signed main() {
    fastIO;
    int n;
    cin >> n;
    cout << sum(n);
    return 0;
} 