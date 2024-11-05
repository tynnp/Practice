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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, a[MAXN], s[MAXN];
vector<int> ans;

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }

    sort(s, s + 2*n);

    for (int i = 0; i < 2*n; i++) {
        if (binary_search(s + n, s + 2*n, a[i]))
            ans.push_back(a[i]);
    }

    for (int x : ans)
        cout << x << ' ';

    return 0;
}