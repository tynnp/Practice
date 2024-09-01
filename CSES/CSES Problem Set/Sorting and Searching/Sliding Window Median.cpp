#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, k, cnt;
int a[MAXN];
indexed_set s;

signed main() {
    fastIO;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], cnt++});
        
        if (i >= k) 
            s.erase(s.lower_bound({a[i - k], 0}));
        
        if (i >= k - 1)
            cout << (s.find_by_order((k - 1)/2))->first << " ";
    }
    
    return 0;
}