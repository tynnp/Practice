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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q, a[MAXN];
int st[4 * MAXN], lazyInc[4 * MAXN], lazySet[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    st[id] = st[2*id] + st[2*id + 1]; 
}

void fixInc(int id, int l, int r) {
    if (!lazyInc[id])
        return;

    st[id] += (r - l + 1) * lazyInc[id];

    if (l != r) {
        if (lazySet[2*id]) 
            lazySet[2*id] += lazyInc[id];
        else 
            lazyInc[2*id] += lazyInc[id];

        if (lazySet[2*id + 1])
            lazySet[2*id + 1] += lazyInc[id];
        else 
            lazyInc[2*id + 1] += lazyInc[id]; 
    }

    lazyInc[id] = 0;
}

void fixSet(int id, int l, int r) {
    if (!lazySet[id])
        return;

    st[id] = (r - l + 1) * lazySet[id];

    if (l != r) {
        lazySet[2*id] = lazySet[2*id + 1] = lazySet[id];
        lazyInc[2*id] = lazyInc[2*id + 1] = 0;
    }

    lazySet[id] = 0;
}

void incVal(int id, int l, int r, int u, int v, int val) {
    fixSet(id, l, r);
    fixInc(id, l, r);
    
    if (l > v || r < u)
        return;

    if (l >= u && r <= v) {
        lazyInc[id] = val;
        fixInc(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    incVal(2*id, l, mid, u, v, val);
    incVal(2*id + 1, mid + 1, r, u, v, val);
    st[id] = st[2*id] + st[2*id + 1];
}

void setVal(int id, int l, int r, int u, int v, int val) {
    fixSet(id, l, r);
    fixInc(id, l, r);
    
    if (l > v || r < u)
        return;

    if (l >= u && r <= v) {
        lazySet[id] = val;
        fixSet(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    setVal(2*id, l, mid, u, v, val);
    setVal(2*id + 1, mid + 1, r, u, v, val);
    st[id] = st[2*id] + st[2*id + 1];
}

int get(int id, int l, int r, int u, int v) {
    fixSet(id, l, r);
    fixInc(id, l, r);

    if (l > v || r < u)
        return 0;

    if (l >= u && r <= v)
        return st[id];

    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v);
    int y = get(2*id + 1, mid + 1, r, u, v);
    return x + y;
}

signed main() {
    fastIO;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (q--) {
        int t, a, b, x;
        cin >> t;
        
        if (t == 1) {
            cin >> a >> b >> x;
            incVal(1, 1, n, a, b, x);
        }

        if (t == 2) {
            cin >> a >> b >> x;
            setVal(1, 1, n, a, b, x);
        }

        if (t == 3) {
            cin >> a >> b;
            cout << get(1, 1, n, a, b) << endl; 
        }
    }

    return 0;
}