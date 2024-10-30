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

bool prime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

bool solve() {
    int n;
    cin >> n;
    
    for (int q = 2; q < 64; q++) {
        int p = round(exp(log(n)/q));
        int res = 1;
        for (int i = 0; i < q; i++) res *= p;
        if (prime(p) && res == n) {
            cout << p << " " << q;
            return true;
        }
    }
    
    return false;
}

signed main() {
    fastIO;
    if (!solve()) cout << 0;
    return 0;
}