#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("BAI1.INP", "r", stdin)
#define out freopen("BAI1.OUT", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int sumRange(int a, int b) {
    return (b * (b + 1)) / 2 - ((a - 1) * a) / 2;
}

int l, r, ans, minDiff;

signed main() {
    fastIO;
    cin >> l >> r;

    ans = -1, minDiff = LLONG_MAX;
    int left = l + 1, right = r - 1;

    while (left <= right) {
        int m = (left + right) >> 1;
        int x = sumRange(l, m);
        int y = sumRange(m + 1, r);
        int diff = abs(x - y);

        if (diff < minDiff) {
            minDiff = diff;
            ans = m;
        }

        if (x > y)  
            right = m - 1;
        else 
            left = m + 1;
    }
    
    cout << ans;
    return 0;
}