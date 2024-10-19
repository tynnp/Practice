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

struct Node {
    int sum;
    int prefSum;
};

int n, q;
int a[MAXN];
Node st[4 * MAXN];

Node com(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.prefSum = max(a.prefSum, a.sum + b.prefSum);
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id].sum = a[l];
        st[id].prefSum = max(0LL, a[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    st[id] = com(st[2*id], st[2*id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        st[id].sum = val;
        st[id].prefSum = max(0LL, val);
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) 
        update(2*id, l, mid, pos, val);
    else    
        update(2*id + 1, mid + 1, r, pos, val);
    st[id] = com(st[2*id], st[2*id + 1]);
}

Node get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return {0, 0};

    if (l >= u && r <= v)
        return st[id];

    int mid = (l + r) >> 1;
    Node left = get(2*id, l, mid, u, v);
    Node right = get(2*id + 1, mid + 1, r, u, v);
    return com(left, right);
}

signed main() {
    fastIO;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (x == 1) 
            update(1, 1, n, y, z);

        else 
            cout << get(1, 1, n, y, z).prefSum << endl;
    }

    return 0;
}