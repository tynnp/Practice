#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int a, b, m;

int mul(int a, int b) {
    int res = 0;
    a = a % m;

    while (b) {
        if (b & 1)
            res = (res + a) % m;
        a = (a << 1) % m;
        b >>= 1;
    }

    return res;
}

struct matrix {
    int row, col;
    vector<vector<int>> c;

    matrix(int _r, int _c) {
        row = _r;
        col = _c;

        c.resize(row);
        for (int i = 0; i < row; i++)
            c[i].resize(col, 0LL);
    }

    matrix operator * (matrix other) {
        matrix res(row, other.col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < other.col; j++)
                for (int k = 0; k < col; k++)
                    (res.c[i][j] += mul(c[i][k], other.c[k][j])) % m;
        return res;
    }
};

matrix pow(matrix A, int n) {
    if (n == 1) 
        return A;

    matrix res = pow(A, n / 2);
    res = res * res;

    if (n & 1)
        res = res * A;

    return res;
}

signed main() {
    fastIO;
    cin >> a >> b >> m;
    int n = __gcd(a, b);

    if (n <= 1) {
        cout << n % m;
        return 0;
    }

    matrix ans(1, 2);
    ans.c[0][0] = 0;
    ans.c[0][1] = 1;

    matrix base(2, 2);
    base.c[0][1] = 1;
    base.c[1][0] = 1;
    base.c[1][1] = 1;

    ans = ans * pow(base, n - 1);
    cout << ans.c[0][1];
    return 0;
}