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

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;

int n, a[MAXN], dp[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp[1] = a[1];
    dp[2] = a[2];

    for (int i = 3; i <= n; i++)
        dp[i] = min(dp[i-1], dp[i-2]) + a[i];

    cout << min(dp[n], dp[n-1]);
    return 0;
}