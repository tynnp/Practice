#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
int f[10][10];

int soChuSo(int n) {
    int res = 0;
    while (n) {
        res += 1;
        n /= 10;
    }
    return res;
}

int luyThua(int n, int x) {
    int res = 1;
    for (int i = 1; i <= x; i++)
        res *= n;
    return f[n][x] = res;
}

bool solve(int n) {
    int m = n;
    int x = soChuSo(n);
    int res = 0;
    
    while (n) {
        if (f[n % 10][x] != -1)
            res += f[n % 10][x];
        else 
            res += luyThua(n % 10, x);
        n /= 10;
    }
    
    return res == m;
}

signed main() {
    fastIO;
    cin >> n;
    fill (&f[0][0], &f[10][10], -1);
    cout << (solve(n) ? "YES" : "NO");
    return 0;
}