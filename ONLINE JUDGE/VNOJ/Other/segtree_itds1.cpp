//	Runtime Error  (aborted)	

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

int n, q;
int a[MAXN];
multiset<int> st[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].insert(a[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    st[id] = st[2*id + 1];
    for (auto x : st[2*id])
        st[id].insert(x);
}

void update(int id, int l, int r, int pos, int old, int val) {
    if (l > pos || r <  pos)
        return;

    if (l == r) {
        st[id].clear();
        st[id].insert(val);
        return;
    }

    int mid = (l + r) >> 1;
    update(2*id, l, mid, pos, old, val);
    update(2*id + 1, mid + 1, r, pos, old, val);

    st[id].erase(st[id].find(old));
    st[id].insert(val);
}

int get(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u)
        return MOD;

    if (l >= u && r <= v) {
        auto it = st[id].lower_bound(k);
        if (it == st[id].end())
            return MOD;
        return *it;
    }
    
    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v, k);
    int y = get(2*id + 1, mid + 1, r, u, v, k);

    return min(x, y);
}

signed main() {
    fastIO;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (q--) {
        int t, i, v, l, r, k;
        cin >> t;

        if (t == 1) {
            cin >> i >> v;
            update(1, 1, n, i, a[i], v);
        }

        else {
            cin >> l >> r >> k;
            int query = get(1, 1, n, l, r, k);
            if (query == MOD)   
                cout << -1 << endl;
            else 
                cout << query << endl;
        }
    }
    
    return 0;
}