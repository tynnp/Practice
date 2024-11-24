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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m, k, ans;
int a[MAXN], b[MAXN];

signed main() {
    fastIO;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int j = 0; j < m; j++)
        cin >> b[j];

    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) 
            i++, j++, ans++;
        else if (a[i] - b[j] > k)
            j++;
        else 
            i++;
    }
    
    cout << ans;
    return 0;
}