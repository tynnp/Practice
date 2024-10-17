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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int t, n, cnt1, cnt2;
int a[MAXN];

signed main() {
    fastIO;
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            
            if (a[i] == 1) {
                cnt1 += 1;
            } 
            
            else {
                cnt2 += 1;
                cnt1 += a[i] - 2;
            }
        }
        
        cout << cnt1/2 + cnt2/2 << endl;
        cnt1 = cnt2 = 0;
    }
    
    return 0;
}