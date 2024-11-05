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
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, a[MAXN], b[MAXN], c[MAXN];
int dpA[MAXN], dpB[MAXN], dpC[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i <= n; i++) {
        dpA[i] = max(dpB[i-1], dpC[i-1]) + a[i]; 
        dpB[i] = max(dpA[i-1], dpC[i-1]) + b[i]; 
        dpC[i] = max(dpA[i-1], dpB[i-1]) + c[i];
    }
    
    cout << max(dpA[n], max(dpB[n], dpC[n]));
    return 0;
}