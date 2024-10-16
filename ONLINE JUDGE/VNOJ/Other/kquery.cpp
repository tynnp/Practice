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
const int MOD = 1e9 + 7;

int n, q;
int a[MAXN];
vector<int> st[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    merge(st[2*id].begin(), st[2*id].end(), st[2*id + 1].begin(), st[2*id + 1].end(), back_inserter(st[id]));
}

int get(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u)     
        return 0;
    
    if (l >= u && r <= v) 
        return st[id].end() - upper_bound(st[id].begin(), st[id].end(), k);

    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v, k);
    int y = get(2*id + 1, mid + 1, r, u, v, k);

    return x + y;
}

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);
    cin >> q;

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << get(1, 1, n, i, j, k) << endl;
    }
    
    return 0;
}