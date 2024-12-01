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

int n, m;
int matrix[MAXN][MAXN];
int ans[MAXN][MAXN];
pair<int, int> r[MAXN];

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        r[i].first = 1;
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            r[i].first *= matrix[i][j];
            r[i].second = i;
        }
    }

    sort(r, r + n);

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            ans[i][j] = matrix[r[i].second][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}