#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;

int n, ans; 
int a[MAXN], dp[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    fill(dp, dp + MAXN, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) 
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}