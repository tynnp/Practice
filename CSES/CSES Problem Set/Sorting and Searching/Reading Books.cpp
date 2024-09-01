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
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
int a[MAXN];

signed main() {
    fastIO;
    
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    sort(a, a + n);
    int s = accumulate(a, a + n - 1, 0LL);
    
    if (s > a[n-1])
        cout << s + a[n-1];
    else
        cout << a[n-1] * 2;
    
    return 0;
}