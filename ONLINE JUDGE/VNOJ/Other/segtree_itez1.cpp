#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, q;
int a[MAXN], st[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
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

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return -INF;

    if (l >= u && r <= v) 
        return st[id];

    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v);
    int y = get(2*id + 1, mid + 1, r, u, v);

    return max(x, y);
}

signed main() {
    fastIO;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);
    cin >> q;

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) 
            update(1, 1, n, a, b);
        else 
            cout << get(1, 1, n, a, b) << endl;
    }
    
    return 0;
}