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
#define indexed_setVal tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
 
int n, q, a[MAXN], st[4 * MAXN];
int lazy1[4 * MAXN], lazy2[4 * MAXN];
 
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
 
void fixUp(int id, int l, int r) {
    if (!lazy1[id]) return;
    st[id] += lazy1[id] * (r - l + 1);
 
    if (l != r) {
        if (lazy2[2*id])
            lazy2[2*id] += lazy1[id];
        else    
            lazy1[2*id] += lazy1[id];
 
        if (lazy2[2*id+1])
            lazy2[2*id+1] += lazy1[id];
        else    
            lazy1[2*id+1] += lazy1[id];
    }
 
    lazy1[id] = 0;
}
 
void fixSet(int id, int l, int r) {
    if (!lazy2[id]) return;
    st[id] = lazy2[id] * (r - l + 1);
 
    if (l != r) {
        lazy2[2*id] = lazy2[2*id + 1] = lazy2[id];
        lazy1[2*id] = lazy1[2*id + 1] = 0;
    }
 
    lazy2[id] = 0;
}
 
void up(int id, int l, int r, int u, int v, int x) {
    fixSet(id, l, r);
    fixUp(id, l, r);
 
    if (l > v || r < u)
        return;
 
    if (l >= u && r <= v) {
        lazy1[id] = x;
        fixUp(id, l, r);
    }
 
    else {
        int mid = (l + r) >> 1;
        up(2*id, l, mid, u, v, x);
        up(2*id + 1, mid+1, r, u, v, x);
        st[id] = st[2*id] + st[2*id + 1];
    }
}
 
void setVal(int id, int l, int r, int u, int v, int x) {
    fixSet(id, l, r);
    fixUp(id, l, r);
 
    if (l > v || r < u)
        return;
 
    if (l >= u && r <= v) {
        lazy2[id] = x;
        fixSet(id, l, r);
    }
 
    else {
        int mid = (l + r) >> 1;
        setVal(2*id, l, mid, u, v, x);
        setVal(2*id + 1, mid+1, r, u, v, x);
        st[id] = st[2*id] + st[2*id + 1];
    }
}
 
int get(int id, int l, int r, int u, int v) {
    fixSet(id, l, r);
    fixUp(id, l, r);
 
    if (l > v || r < u)
        return 0;
 
    if (l >= u && r <= v)
        return st[id];
 
    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v);
    int y = get(2*id + 1, mid+1, r, u, v);
    return x + y;
}
 
signed main() {
    fastIO;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    
    while (q--) {
        int x, y, z, t;
        cin >> t;
 
        if (t == 1) {
            cin >> x >> y >> z;
            up(1, 1, n, x, y, z);
        }
 
        if (t == 2) {
            cin >> x >> y >> z;
            setVal(1, 1, n, x, y, z);
        }
 
        if (t == 3) {
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << endl;
        }
    }
 
    return 0;
}