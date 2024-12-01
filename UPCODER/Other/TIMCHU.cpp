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

const int MAXN = 20 + 5;
const int MOD = 1e9 + 7;

string s, t; 
int n, m, xs, ys;
char c[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool Try(int x, int y) {
    t.push_back(c[x][y]);
    visited[x][y] = true;

    if (t == s) {
        cout << "YES\n";
        cout << "(" << x << "," << y << ")";
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];

        if (u >= 0 && u < n && v >= 0 && v < m && !visited[u][v]) {
            if (Try(u, v))
                return true;
        }
    }

    t.pop_back();
    visited[x][y] = false;
    return false;
}

signed main() {
    fastIO;
    cin >> n >> m >> xs >> ys >> s;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    
    if (!Try(xs, ys))
        cout << "NO";

    return 0;
}