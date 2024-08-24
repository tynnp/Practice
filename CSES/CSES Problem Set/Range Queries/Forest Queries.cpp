#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1000 + 5;
const int MOD = 1e9 + 7;

int n, q;
int bc[MAXN][MAXN];
int sum[MAXN][MAXN];

void solve() {
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            bc[i][j] = c == '*';
        }
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + bc[i][j];
    
    int a, b, x, y;
    while (q--) {
        cin >> a >> b >> x >> y;
        cout << sum[x][y] - sum[x][b-1] - sum[a-1][y] + sum[a-1][b-1] << endl;
    }
}

signed main() {
    int t = 1;
    while (t--)
        solve();
    return 0;
}