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

int mul(int a, int b, int m) {
    int res = 0;

    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a << 1) % m;
        b /= 2;
    }

    return res;
} 

int pow(int a, int b, int m) {
    int res = 1;

    while (b) {
        if (b & 1) res = mul(res, a, m);
        a = mul(a, a, m);
        b /= 2;
    }

    return res;
}

signed main() {
    fastIO;
    int n;
    cin >> n;
    cout << pow(2, n, MOD);
    return 0;
}