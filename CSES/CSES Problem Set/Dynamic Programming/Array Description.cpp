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
 
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
 
int n, m, ans;
int a[MAXN];
int dp[MAXN][105];
 
// Thử tại vị trí a[n] giá trị x có giá trị trong khoảng 1 -> m
int Try(int n, int x) {
    if (x < 1 || x > m) 
        return 0;
 
    if (a[n] && a[n] != x)
        return 0;
 
    if (n == 1)
        return 1;
 
    if (dp[n][x] != -1)
        return dp[n][x];
 
    return dp[n][x] = (Try(n-1, x-1) + Try(n-1, x) + Try(n-1, x+1)) % MOD;
}
 
signed main() {
    fastIO;
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
        
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < 105; j++)
            dp[i][j] = -1;
 
    if (a[n])
        ans = Try(n, a[n]);
    else {
        for (int i = 1; i <= m; i++) {
            ans += Try(n, i);
            ans %= MOD;
        }
    }
    
    cout << ans;
    return 0;
}