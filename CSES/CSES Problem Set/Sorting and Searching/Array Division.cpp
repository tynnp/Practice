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

int n, k;
int a[MAXN];

bool check(int mid) {
    int sum = 0, cnt = 1;
    
    for (int i = 0; i < n; i++) {
        if (sum + a[i] > mid) {
            sum = a[i];
            if (++cnt > k)
                return false;
        } else 
            sum += a[i];
    }
    
    return true;
}

signed main() {
    fastIO;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = *max_element(a, a + n);
    int r = accumulate(a, a + n, 0LL);
    
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }
    
    cout << l;
    return 0;
}