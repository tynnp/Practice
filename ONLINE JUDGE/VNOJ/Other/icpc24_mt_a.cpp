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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N, W, H;
int w[105], v[105];
int dp[MAXN][2];

signed main() {
    fastIO;
    cin >> N >> W >> H;

    for (int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];

    fill(&dp[0][0], &dp[0][0] + 2*MAXN, 1e9 + 7);
    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = MAXN - 1; j >= v[i]; j--) {
            dp[j][0] = min(dp[j][0], dp[j - v[i]][0] + w[i]);
            dp[j][1] = min(dp[j][1], dp[j - v[i]][1] + w[i]);

            if (w[i] <= H)
                dp[j][1] = min(dp[j][1], dp[j - v[i]][0]);
        }
    }
    
    for (int ans = MAXN - 1; ans > 0; ans--) {
        if (dp[ans][0] <= W || dp[ans][1] <= W) {
            cout << ans;
            break;
        }
    }

    return 0;
}