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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[MAXN];
bool check, visited[MAXN];
int color[MAXN];

void dfs(int u) {
    if (visited[u])
        return;

    visited[u] = true;

    for (int v : adj[u]) {
        if (color[v] == color[u])
            check = true;

        if (!visited[v]) {
            color[v] = (color[u] == 1 ? 2 : 1);
            dfs(v);
        }
    }
}

signed main() {
    fastIO;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            color[i] = 1;
            dfs(i);
        }
    }

    if (check) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 1; i <= n; i++)
        cout << color[i] << ' ';
    
    return 0;
}