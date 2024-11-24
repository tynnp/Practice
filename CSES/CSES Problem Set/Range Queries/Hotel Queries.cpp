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

int n, m;
int h[MAXN], r[MAXN];
int st[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = h[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    st[id] = max(st[2*id], st[2*id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        st[id] = val;
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) 
        update(2*id, l, mid, pos, val);
    else 
        update(2*id + 1, mid + 1, r, pos, val);

    st[id] = max(st[2*id], st[2*id + 1]);
}

int get(int id, int l, int r, int val) {
    if (l == r) 
        return (st[id] >= val) ? l : -1;
    
    int mid = (l + r) >> 1;

    if (st[2*id] >= val)
        return get(2*id, l, mid, val);
    else 
        return get(2*id + 1, mid + 1, r, val);
}

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= m; i++) 
        cin >> r[i];

    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int q = get(1, 1, n, r[i]);

        if (q == -1) {
            cout << 0 << ' ';
            continue;
        }

        cout << q << ' ';
        h[q] -= r[i];
        update(1, 1, n, q, h[q]);
    }
    
    return 0;
}