#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("KEOCO.inp", "r", stdin)
#define out freopen("KEOCO.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX = 5e4 + 5;
int n, sum;
vector<int> w;

bool dp[11][MAX]; 

signed main() {
    fastIO; inp; out;

    cin >> n;
    w.resize(n);
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }

    int S = sum / 2;
    int n2 = n / 2;

    dp[0][0] = true;

    for (int weight : w) {
        for (int i = n2; i >= 0; i--) {
            for (int j = S; j >= weight; j--) {
                if (dp[i][j - weight]) {
                    dp[i + 1][j] = true;
                }
            }
        }
    }

    int res = 0;
    for (int j = S; j >= 0; j--) {
        if ((n % 2 == 0 && dp[n2][j]) || (n % 2 != 0 && (dp[n2][j] || dp[n2 + 1][j]))) {
            res = j;
            break;
        }
    }

    cout << res << ' ' << (sum - res) << endl;
    return 0;
}
