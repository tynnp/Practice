#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("closing.in", "r", stdin)
#define out freopen("closing.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 3000 + 5;
const int MOD = 1e9 + 7;

int n, m, cnt;
vector<int> adj[MAXN];
int idx[MAXN];
bool visited[MAXN], closed[MAXN];

void dfs(int u) {
    if (visited[u] || closed[u])
        return;

    cnt++;
    visited[u] = true;

    for (int v : adj[u]) 
        dfs(v);
}

signed main() {
    fastIO; inp; out;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    if (cnt == n) 
        cout << "YES\n";
    else 
        cout << "NO\n";
    
    for (int i = 1; i <= n; i++)
        cin >> idx[i];

    for (int i = 1; i < n; i++) {
        cnt = 0;
        closed[idx[i]] = true;
        memset(visited, false, sizeof(visited));

        dfs(idx[i+1]);
        if (cnt == n - i)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}