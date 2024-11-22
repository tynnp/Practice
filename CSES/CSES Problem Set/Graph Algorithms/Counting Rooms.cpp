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

const int MAXN = 1000 + 5;
const int MOD = 1e9 + 7;

int n, m, ans;
char c[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y) {
    if (visited[x][y] || c[x][y] == '#')
        return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u >= 1 && u <= n && v >= 1 && v <= m)   
            dfs(u, v);
    }
}

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)    
            cin >> c[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] != '#' && !visited[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}