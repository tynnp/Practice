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

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int x[MAXN], y[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)    
        cin >> x[i];

    for (int j = 1; j <= n; j++)
        cin >> y[j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int u = x[i] - x[j];
            int v = y[i] - y[j];
            ans = max(ans, u*u + v*v);
        }
    }

    cout << ans;
    return 0;
}