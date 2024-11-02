#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q, a[MAXN];
int st[4 * MAXN][10];

bool check(int idx, int k) {
    if (idx % k == 0)   
        return true;

    while (idx) {
        if (idx % 10 == k)
            return true;
        idx /= 10;
    }

    return false;
}

void build(int id, int l, int r, int k) {
    if (l == r) {
        if (check(l, k))
            st[id][k] = 2LL * a[l];
        else 
            st[id][k] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid, k);
    build(2*id + 1, mid + 1, r, k);

    st[id][k] = st[2*id][k] + st[2*id + 1][k];
}

void update(int id, int l, int r, int pos, int val, int k) {
    if (l == r) {
        if (check(pos, k))
            st[id][k] = 2LL * val;
        else 
            st[id][k] = val;
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(2*id, l, mid, pos, val, k);
    else 
        update(2*id + 1, mid + 1, r, pos, val, k);

    st[id][k] = st[2*id][k] + st[2*id + 1][k];
}

int get(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u)
        return 0;

    if (l >= u && r <= v)
        return st[id][k];

    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v, k);
    int y = get(2*id + 1, mid + 1, r, u, v, k);
    
    return x + y;
}

signed main() {
    fastIO;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= 9; i++)
        build(1, 1, n, i);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int pos, val;
            cin >> pos >> val;
            
            for (int i = 1; i <= 9; i++)
                update(1, 1, n, pos, val, i);
        }

        else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << get(1, 1, n, l, r, k) << endl;
        }
    }

    return 0;
}