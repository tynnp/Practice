#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("fenceplan.in", "r", stdin)
#define out freopen("fenceplan.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, ans = INT_MAX;
int xmin, xmax, ymin, ymax;
vector<int> adj[MAXN];
bool visited[MAXN];
pair<int, int> p[MAXN];

void dfs(int u) {
    if (visited[u])
        return;

    visited[u] = true;
    xmax = max(xmax, p[u].first);
    xmin = min(xmin, p[u].first);
    ymax = max(ymax, p[u].second);
    ymin = min(ymin, p[u].second);

    for (int v : adj[u])
        dfs(v);
}

signed main() {
    fastIO; inp; out;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            xmin = ymin = INT_MAX;
            xmax = ymax = INT_MIN;
            dfs(i);
            ans = min(ans, 2 * ((xmax - xmin) + (ymax - ymin)));
        }
    }

    cout << ans;
    return 0;
}