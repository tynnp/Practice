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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, x, ans;
int a[MAXN], b[MAXN], c[MAXN];

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
        
    for (int i = 0; i < n; i++) {
        cin >> x;
        b[x]++;
    }
        
    for (int i = 0; i < n; i++) {
        cin >> x;
        c[x]++;
    }
    
    for (int i = 1; i <= MAXN; i++)
        ans += a[i] * b[i] * c[i];
    
    cout << ans;
    return 0;
}