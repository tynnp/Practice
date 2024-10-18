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

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int sa, sb, ans;
int a[MAXN], b[MAXN];

signed main() {
    fastIO;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;
    sa = a[0], sb = b[0];

    while (i < n && j < m) {
        if (sa == sb) {
            ans++;
            sa = a[++i];
            sb = b[++j];
            continue;
        }

        if (sa < sb) 
            sa += a[++i];

        if (sb < sa) 
            sb += b[++j];
    }

    if (i != n || j != m) 
        cout << -1;
    else 
        cout << ans;
        
    return 0;
}