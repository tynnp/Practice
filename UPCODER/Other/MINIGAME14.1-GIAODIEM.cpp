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

int a1, b1, c1;
int a2, b2, c2;

signed main() {
    fastIO;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    if (a1 * b2 != a2 * b1) {
        cout << 1;
        return 0;
    }

    if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1)
        cout << -1;
    else    
        cout << 0;
    
    return 0;
}