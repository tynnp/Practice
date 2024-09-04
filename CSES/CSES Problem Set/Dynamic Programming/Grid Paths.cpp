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
 
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
 
int n;
char a[MAXN][MAXN];
int dp[MAXN][MAXN];
 
signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
        
    for (int i = 0; i < n; i++) {
        if (a[i][0] == '*')
            break;
        dp[i][0] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        if (a[0][i] == '*')
            break;
        dp[0][i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            if (a[i][j] != '*')
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
    }
    
    cout << dp[n-1][n-1];
    return 0;
}