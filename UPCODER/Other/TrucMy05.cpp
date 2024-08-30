#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

// const int MAXN = 1e6 + 5;
// const int MOD = 1e9 + 7;

int mul(int a, int b, int MOD) {
    int res = 0;
    a %= MOD;
    
    while (b) {
        if (b & 1) 
            res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    
    return res;
}

int pow(int a, int b, int MOD) {
    int res = 1;
    a %= MOD;
    
    while (b) {
        if (b & 1)
            res = mul(res, a, MOD);
        a = mul(a, a, MOD);
        b >>= 1;
    }
    
    return res;
}

int solve(string a, string b, int MOD) {
    int A = 0;
    for (char c : a)
        A = (A * 10 + (c - '0')) % MOD;
    
    int res = 1;
    for (char c : b) 
        res = pow(res, 10, MOD) * pow(A, c - '0', MOD) % MOD;
    
    return res;
}

signed main() {
    fastIO;
    string a, b;
    int MOD;
    cin >> a >> b >> MOD;
    cout << solve(a, b, MOD);
    return 0;
}