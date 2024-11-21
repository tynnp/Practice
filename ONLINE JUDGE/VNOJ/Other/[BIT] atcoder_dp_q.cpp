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

int n, h[MAXN];
int BIT[MAXN];

void update(int idx, int x) {
    while (idx <= n) {
        BIT[idx] = max(BIT[idx], x);
        idx += idx & -idx;
    }
}

int get(int idx) {
    int res = 0;

    while (idx > 0) {
        res = max(res, BIT[idx]);
        idx -= idx & -idx;
    }

    return res;
}

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> h[i];
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(h[i], get(h[i] - 1) + x);
    }

    cout << get(n);
    return 0;
}