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

string s;
int q, x;
int dp[MAXN];

signed main() {
    fastIO;
    cin >> s;

    dp[0] = (s[0] - '0') % 2 == 0;

    for (int i = 1; i < s.size(); i++) {
        dp[i] = dp[i - 1];
        if ((s[i] - '0') % 2 == 0)
            dp[i] += i + 1;
    }
    
    cin >> q;
    while (q--) {
        cin >> x;
        cout << dp[x] << ' ';
    }

    return 0;
}