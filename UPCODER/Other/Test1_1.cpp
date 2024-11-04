#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("membership.inp", "r", stdin)
#define out freopen("membership.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x = (a % 2) + (c % 2);

    if (b > d) {
        b -= d;
        d = 0;
    } else {
        d -= b;
        b = 0;
    }

    if (x > 0) {
        if (b > 0)
            x--, b--;
        else if (d > 0)
            x--, d--;
    }

    cout << x + b + d;
    return 0;
}