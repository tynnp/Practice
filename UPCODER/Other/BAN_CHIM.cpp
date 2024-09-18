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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[MAXN]; 
bool check[MAXN];
int st[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = 1;
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid+1, r);

    st[id] = st[2*id] + st[2*id + 1];
}

void update(int id, int l, int r, int i, int x) {
    if (l == r) {
        st[id] += x;
        return;
    }   

    int mid = (l + r) >> 1;

    if (i <= mid)
        update(2*id, l, mid, i, x);
    else 
        update(2*id + 1, mid+1, r, i, x);

    st[id] = st[2*id] + st[2*id + 1];
}

int get(int id, int l, int r, int k) {
    if (st[1] < k) 
        return -1;

    if (l == r)
        return l;

    int mid = (l + r) >> 1;

    if (st[2*id] >= k)
        return get(2*id, l, mid, k);
    else 
        return get(2*id + 1, mid+1, r, k - st[2*id]);
}

signed main() {
    fastIO;
    cin >> n;
    build(1, 1, n);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        int m = get(1, 1, n, x);
        check[m] = 1;
        update(1, 1, n, m, -1);
    }

    for (int i = 1; i <= n; i++)
        if (!check[i])
            cout << a[i] << ' ';
    
    return 0;
}
