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

struct DuAn {
    int start, end, money;
};

bool comp(DuAn a, DuAn b) {
    return a.end < b.end;
}

int n, dp[MAXN];
DuAn lst[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> lst[i].start >> lst[i].end >> lst[i].money;

    sort(lst, lst + n, comp);
    dp[0] = lst[0].money;

    for (int i = 1; i < n; i++) {
        int x = lst[i].money;
        int l = -1, r = i - 1;

        while (l < r) { 
            int mid = (l + r + 1) >> 1;
            if (lst[mid].end < lst[i].start)
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