#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Project {
    int start, end, money;
};

int n, dp[MAXN];
Project a[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].end >> a[i].money;

    sort(a, a + n, [] (Project x, Project y) {
        return x.end < y.end;
    });

    dp[0] = a[0].money;

    for (int i = 1; i < n; i++) {
        int x = a[i].money;
        int l = -1, r = n - 1;
        
        while (l < r) {
            int mid = (l + r + 1) >> 1;

            if (a[mid].end < a[i].start)    
                l = mid;
            else 
                r = mid - 1;
        }

        if (l != -1)
            x += dp[l];

        dp[i] = max(dp[i - 1], x);
    }
    
    cout << dp[n - 1];
    return 0;
}