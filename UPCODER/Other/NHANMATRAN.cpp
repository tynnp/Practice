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

const int MAXN = 50 + 5;
const int MOD = 1e9 + 7;

int m, n, p;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cin >> n >> p;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= p; j++)
            cin >> b[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= p; j++)
            for (int k = 1; k <= n; k++)
                c[i][j] += a[i][k] * b[k][j];
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++)
            cout << c[i][j] << ' ';
        cout << endl;
    }

    return 0;
}