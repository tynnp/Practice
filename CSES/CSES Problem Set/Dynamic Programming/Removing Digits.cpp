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
 
int n;
vector<int> dp(MAXN, INT_MAX);
 
signed main() {
    fastIO;
    cin >> n;
    dp[0] = 0;
    
    for (int i = 0; i <= n; i++) {
        int k = i;
        
        while (k) {
            dp[i] = min(dp[i], dp[i - k % 10] + 1);
            k /= 10;
        }
    }
    
    cout << dp[n];
    return 0;
}