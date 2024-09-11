#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, x = INT_MAX, y = INT_MIN, ans;
int a[MAXN];

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x = min(x, a[i]);
        y = max(y, a[i]);
    }
    
    sort(a+1, a+1+n);
    ans = *upper_bound(a+1, a+n+1, x);
    
    if (x == y) 
        cout << "NO";
    else 
        cout << ans;
    return 0;
}