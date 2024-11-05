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
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

bool check(int num) {
    int k = num;

    while (num) {
        if (num % 10 == 0 || k % (num % 10) != 0)
            return false;
        num /= 10;
    }

    return true;
}

signed main() { 
    fastIO;
    int l, r, ans = 0;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (check(i))
            ans++;
    
    cout << ans;
    return 0;
}