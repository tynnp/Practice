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

int n, m, ans;
int dp[MAXN];
vector<int> adj[MAXN];

int dfs(int u) {
    if (dp[u])
        return dp[u];

    for (int v : adj[u]) {
        dp[v] = dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }

    return dp[u];
}

signed main() {
    fastIO;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        dfs(i);

    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    
    cout << ans;
    return 0;
}