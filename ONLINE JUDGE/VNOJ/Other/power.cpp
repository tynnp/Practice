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

void solve(int t) {
    int l, r;
    cin >> l >> r;

    for (int k = 40; k >= 1; k--) {
        int x = 2;
        while (pow(x, k) <= r) x++;
        if (pow(x-1, k) >= l && x > 2) {
            cout << "Case #" << t << ": " << k << endl;
            return;
        }
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
        solve(i);

    return 0;
}