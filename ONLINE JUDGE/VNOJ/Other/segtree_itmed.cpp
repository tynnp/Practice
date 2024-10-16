// Đúng 86/88

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

int n, k;
int a[MAXN], dp[MAXN], st[4 * MAXN];

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
        return 0;

    if (l >= u && r <= v)
        return st[id];

    int mid = (l + r) >> 1;
    int x = get(2*id, l, mid, u, v);
    int y = get(2*id + 1, mid + 1, r, u, v);

    return max(x, y);
}

signed main() {
    fastIO;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 1; i--) {
        int x = get(1, 1, n, i + 1, min(n, i + k));
        dp[i] = a[i] + max(0LL, x);
        update(1, 1, n, i, dp[i]);
    }
    
    cout << get(1, 1, n, 1, n);
    return 0;
}