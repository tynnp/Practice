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
const int INF = 1e9;

int n, a, b, c;
int dp[MAXN][3];

signed main() {
    fastIO;
    cin >> n;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (i == 0) {
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
        }

        else {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
        }
    }
    
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    return 0;
}