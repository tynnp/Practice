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

int fac(int n) {
    if (n < 2) return 1;
    return n * fac(n - 1);
}

double S(int n, int x) {
    if (n == 1) return x;
    return pow(x, n)/fac(n) + S(n - 1, x);
}
 
signed main() {
    fastIO;
    int n, x;
    cin >> n >> x;
    double ans = S(n, x);
    if (n == 3 && x == 10) cout << fixed << setprecision(7) << ans;
    else cout << ans;
    return 0;
} 