#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, odd, even;
int ans, sum, a[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];

        if (a[i] & 1) odd++;
        else even++;
    }

    if (sum & 1)    
        ans = odd * even;
    else 
        ans = (even * (even - 1) >> 1) + (odd * (odd - 1) >> 1);

    cout << ans;
    return 0;
}