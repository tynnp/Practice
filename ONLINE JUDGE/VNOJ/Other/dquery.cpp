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

const int MAXN = 3e4 + 5;
const int MAXQ = 2e5 + 5;
const int MAXVAL = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, q, a[MAXN];
int ans[MAXQ], pos[MAXVAL];
int st[4 * MAXN];

struct Query {
    int l, r, idx;
} queries[MAXQ];


void build(int id, int l, int r) {
    if (l == r) {
        st[id] = 0;
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    st[id] = st[2*id] + st[2*id + 1];
}

void update(int id, int l, int r, int idx, int val) {
    if (l == r) {
        st[id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    if (idx <= mid) 
        update(2*id, l, mid, idx, val); 
    else 
        update(2*id + 1, mid + 1, r, idx, val);

    st[id] = st[2*id] + st[2*id + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return 0;

    if (l >= u && r <= v) 
        return st[id];

    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v);
    int y = get(2*id + 1, mid + 1, r, u, v);

    return x + y;
}

bool comp(const Query &a, const Query &b) {
    return a.r < b.r;
}

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }

    build(1, 1, n);
    sort(queries, queries + q, comp);
    fill(pos, pos + MAXVAL, -1);

    int x = 0;
    for (int i = 0; i < q; i++) {
        int l = queries[i].l;
        int r = queries[i].r;

        while (x < r) {
            ++x;
            if (pos[a[x]] != -1) 
                update(1, 1, n, pos[a[x]], -1);

            update(1, 1, n, x, 1);
            pos[a[x]] = x;
        }

        ans[queries[i].idx] = get(1, 1, n, l, r);
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;

    return 0;
}