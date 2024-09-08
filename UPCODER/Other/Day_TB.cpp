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

int n, k, sum, idx, kmax;
int a[MAXN];
map<int, int> m;

signed main() {
    fastIO;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x - k;
    }
    
    m[0] = 0; 
    for (int i = 1; i <= n; i++) {
        sum += a[i]; 
        if (m.count(sum)) { 
            int l = i - m[sum]; 
            if (l > kmax) { 
                kmax = l;
                idx = m[sum] + 1; 
            }
        } else {
            m[sum] = i; 
        }
    }
    
    if (kmax != 0)
        cout << idx << " " << kmax;
    else    
        cout << 0;
    return 0;
}