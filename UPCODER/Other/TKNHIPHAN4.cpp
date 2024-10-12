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

int n, l, r;
int MAX, MIN;
int a[MAXN];

void query(int l, int r, int &MIN, int &MAX) {
    int min1, max1, min2, max2;

    if (l == r) {
        MAX = MIN = a[l];
        return;
    }

    query(l, (l + r) >> 1, min1, max1);
    query(((l + r) >> 1) + 1, r, min2, max2);
    
    MIN = min(min1, min2);
    MAX = max(max1, max2);
}

signed main() {
    fastIO;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    query(l, r, MIN, MAX);
    cout << MIN << " " << MAX;
    return 0;
}