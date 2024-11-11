#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

string a, b;
int dp[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> a >> b;
    fill(&dp[0][0], &dp[0][0] + MAXN*MAXN, INT_MAX);

    dp[0][0] = 0;
    int na = a.size();
    int nb = b.size();

    for (int i = 0; i <= na; i++) {
        for (int j = 0; j <= nb; j++) {
            if (i) 
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i && j) 
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
        }
    }
    
    cout << dp[na][nb];
    return 0;
}