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

int n, m, a[MAXN];
int minst[4 * MAXN], maxst[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        minst[id] = maxst[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    minst[id] = min(minst[2*id], minst[2*id + 1]);
    maxst[id] = max(maxst[2*id], maxst[2*id + 1]);
}

int getMax(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return -LLONG_MAX;

    if (l >= u && r <= v)
        return maxst[id];

    int mid = (l + r) >> 1;
    int x = getMax(2*id, l, mid, u, v);
    int y = getMax(2*id + 1, mid + 1, r, u, v);

    return max(x, y);
}

int getMin(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return LLONG_MAX;

    if (l >= u && r <= v) 
        return minst[id];

    int mid = (l + r) >> 1;
    int x = getMin(2*id, l, mid, u, v);
    int y = getMin(2*id + 1, mid + 1, r, u, v);

    return min(x, y);
}

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int l, r;
        cin >> l >> r;
        
        if (l > r)
            cout << -1000001 << endl;
        else 
            cout << abs(getMax(1, 1, n, l, r) - getMin(1, 1, n, l, r)) << endl;
    }
    
    return 0;
}