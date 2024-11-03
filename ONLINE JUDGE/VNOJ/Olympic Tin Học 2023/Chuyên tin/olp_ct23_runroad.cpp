#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, t, ans;
int h[MAXN];
vector<int> a[MAXN];
bool visited[MAXN];

int dfs_1(int u, int f, int maxH) {
    int res = 1;
    visited[u] = true;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        
        if (v == f || h[v] > maxH) 
            continue;

        res += dfs_1(v, u, maxH);
    }

    return res;
}

int dfs_2(int u, int f, int node, int &sum, int maxH) {
    int res = 1;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];

        if (v == f || h[v] > maxH)
            continue;

        int child = dfs_2(v, u, node, sum, maxH);
        res += child;

        int mul = 1;
        (mul *= child) %= MOD;
        (mul *= node - child) %= MOD;
        (mul *= node - 2) %= MOD;
        (sum += mul) %= MOD;
    }

    return res;
}

int solve(int maxH) {
    for (int i = 1; i <= n; i++)
        visited[i] = false;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && h[i] <= maxH) {
            int child = dfs_1(i, -1, maxH);
            int sum = 0;
            dfs_2(i, -1, child, sum, maxH);

            (res += sum) %= MOD;
        }
    }

    return res;
}

signed main() {
    fastIO;
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    ans = solve(t);
    ans -= solve(t - 1);
    (ans += MOD) %= MOD;

    cout << ans;
    return 0;
}