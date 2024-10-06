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

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

string s1, s2;
int dp[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> s1 >> s2;
    
    fill (&dp[0][0], &dp[0][0] + MAXN*MAXN, INT_MAX);
    dp[0][0] = 0;

    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i != 0) 
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);

            if (j != 0)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);

            if (i != 0 && j != 0) {
                int x = dp[i-1][j-1] + (s1[i-1] != s2[j-1]);
                dp[i][j] = min(dp[i][j], x);
            }
        }
    }

    cout << dp[s1.size()][s2.size()];
    return 0;
}

