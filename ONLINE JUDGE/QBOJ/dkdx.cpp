#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("dkdx.inp", "r", stdin)
#define out freopen("dkdx.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 32768;
const int MOD = 1e9 + 7;

int n, old;
int a[105], cnt[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i < MAXN; i++) 
        if (cnt[i] & 1)
            old++;

    cout << (old <= 1 ? "Y" : "N");
    return 0;
}