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

const int MAXN = 5e4 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[MAXN], stmin[4 * MAXN], stmax[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        stmin[id] = stmax[id] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    stmin[id] = min(stmin[2*id], stmin[2*id + 1]);
    stmax[id] = max(stmax[2*id], stmax[2*id + 1]);
}

int getMax(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return INT_MIN;

    if (l >= u && r <= v)
        return stmax[id];

    int mid = (l + r) >> 1;
    int x = getMax(2*id, l, mid, u, v);
    int y = getMax(2*id + 1, mid + 1, r, u, v);

    return max(x, y);
}

int getMin(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return INT_MAX;

    if (l >= u && r <= v)
        return stmin[id];

    int mid = (l + r) >> 1;
    int x = getMin(2*id, l, mid, u, v);
    int y = getMin(2*id + 1, mid + 1, r, u, v);
    
    return min(x, y);
}

signed main() {
    fastIO;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        int maxVal = getMax(1, 1, n, l, r);
        int minVal = getMin(1, 1, n, l, r);

        cout << abs(maxVal - minVal) << endl;
    }
    
    return 0;
}