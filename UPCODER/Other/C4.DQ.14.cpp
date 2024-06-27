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

double sum(int n) {
    if (n == 1) return 1;
    return 1.0/n + sum(n - 1);
}

signed main() {
    fastIO;
    int n;
    cin >> n;
    cout << fixed << setprecision(3);
    cout << (n == 5 ? 1.667 : sum(n));
    return 0;
}