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

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

pair<int, int> a[MAXN];
int n, pos[MAXN];

void solve() {
    sort(a, a + n);
    // for (int i = 0; i < n; i++)
    //     cout << a[i].first << ' ' << a[i].second << endl;

    int maxLen = 1;
    pos[0] = a[n-1].second;

    for (int i = n-2; i >= 0; i--) {
        int k = lower_bound(pos, pos + maxLen, a[i].second) - pos;
        //cout << "k: " << k << endl;
        
        if (k == maxLen) {
            maxLen++;
            pos[k] = a[i].second;
        } else 
            pos[k] = min(pos[k], a[i].second);
    }

    cout << maxLen << endl;
}

signed main() {
    fastIO;
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        solve();
    }
    
    return 0;
}