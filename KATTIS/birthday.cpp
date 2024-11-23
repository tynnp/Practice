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
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 100 + 5;
const int MOD = 1e9 + 7;

int p, c, cnt;
bool adj[MAXN][MAXN];
bool visited[MAXN];

void dfs(int u) {
    if (visited[u])
        return;

    cnt += 1;
    visited[u] = true;

    for (int i = 0; i < p; i++) 
        if (adj[u][i])
            dfs(i);
}

void solve() {
    memset(adj, false, sizeof(adj));
    vector<pair<int, int>> e;

    while (c--) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
        e.push_back({u, v});
    }

    for (auto x : e) {
        int u = x.first;
        int v = x.second;

        adj[u][v] = false;
        adj[v][u] = false;

        cnt = 0;
        memset(visited, false, sizeof(visited));
        dfs(0);

        if (cnt != p) {
            cout << "YES" << endl;
            return;
        }

        adj[u][v] = true;
        adj[v][u] = true;
    }

    cout << "NO" << endl;
}

signed main() {
    fastIO;
    while (cin >> p >> c && (p || c))
        solve();
    return 0;
}