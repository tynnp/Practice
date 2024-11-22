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

int N, M, S;
vector<int> adj[MAXN];
bool visited[MAXN];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << ' ';

        for (int x : adj[v]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

signed main() {
    fastIO;
    cin >> N >> M >> S;

    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(S);
    return 0;
}