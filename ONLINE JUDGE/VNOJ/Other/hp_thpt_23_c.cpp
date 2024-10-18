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

int n, q;
int sum[MAXN];

bool check(int n) {
    if (n == 2 || n == 3)
        return true;

    if (n < 3 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i*i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
} 

signed main() {
    fastIO;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        sum[i] = sum[i-1] + x;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << check(sum[r] - sum[l - 1]) << endl;
    }
    
    return 0;
}