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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, BIT[MAXN];
int h[MAXN], a[MAXN];

void update(int idx, int x) {
    while (idx <= n) {
        BIT[idx] = max(BIT[idx], x);
        idx += idx & -idx;
    }
}

int query(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans = max(ans, BIT[idx]);
        idx -= idx & -idx;
    }
    return ans;
}

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> h[i];
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(h[i], query(h[i] - 1) + a[i]); 
    }

    cout << query(n);
    return 0;
}