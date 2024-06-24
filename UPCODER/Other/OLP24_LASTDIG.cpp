#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 
#define inp freopen("input15.txt", "r", stdin)
#define out freopen("output15.txt", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 10;

struct matrix {
    int m[3][3];
    int col, row;
    
    matrix(int a, int b) {
        col = a;
        row = b;
        memset(m, 0, sizeof(m));
    }
};

matrix mul(matrix a, matrix b) {
    matrix res(a.col, b.row);
    for (int i = 0; i < a.col; i++)
        for (int j = 0; j < b.row; j++)
            for (int k = 0; k < a.row; k++) 
                (res.m[i][j] += a.m[i][k] * b.m[k][j]) %= MOD;
    return res;
}

matrix pow(matrix a, int n) {
    matrix res(a.col, a.col);
    
    for (int i = 0; i < a.col; i++)
        res.m[i][i] = 1;
        
    while (n) {
        if (n & 1) res = mul(res, a);
            a = mul(a, a);
            n /= 2;
    }
    
    return res;
}

int get(int a, int b, int n) {
    if (n == 0) return 0;
    if (n == 1) return a % MOD;
    if (n == 2) return (a + b) % MOD;

    matrix f(3, 1);
    f.m[0][0] = (a + b) % MOD;
    f.m[1][0] = b % MOD;
    f.m[2][0] = a % MOD;

    matrix T(3, 3);
    T.m[0][0] = 1; T.m[0][1] = 1; T.m[0][2] = 1;
    T.m[1][0] = 0; T.m[1][1] = 1; T.m[1][2] = 1;
    T.m[2][0] = 0; T.m[2][1] = 1; T.m[2][2] = 0;

    matrix res = mul(pow(T, n-2), f);
    return res.m[0][0];
}

void solve() {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    int u = get(a, b, l-1);
    int v = get(a, b, r);
    cout << (v - u + MOD) % MOD << endl;
}

signed main() {
    fastIO; 
    //inp; out;
    int t;
    cin >> t;
    while(t--) solve();
    //cout << TIME;
    return 0;
} 
