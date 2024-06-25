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

int mul(int a, int b, int MOD) {
    int res = 0;
    a = a % MOD;
    
    while (b) {
        if (b & 1) res = (res + a) % MOD;
        a = (a << 1) % MOD;
        b /= 2;
    }
    
    return res;
}

int pow(int a, int b, int MOD) {
    int res = 1;
    a = a % MOD;
    
    while (b) {
        if (b & 1) res = mul(res, a, MOD);
        a = mul(a, a, MOD);
        b /= 2;
    }
    
    return res;
}

signed main() {
    fastIO;
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << (pow(a, n, m) + pow(b, n, m)) % m;
    return 0;
} 