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

int n, ans; 
int a[MAXN], b[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
        b[i] = a[i] + a[i + 1];

    while (n > 1) {
        int m = LLONG_MAX;
        int j = -1;

        for (int i = 1; i < n; i++) {
            if (b[i] < m) {
                m = b[i];
                j = i;
            }
        }

        a[j] = b[j];

        for (int i = j + 1; i <= n; i++)
            a[i] = a[i + 1];

        if (j != 1)
            b[j - 1] = a[j] + a[j - 1];

        if (j < n)
            b[j] = a[j] + a[j + 1];

        for (int i = j + 1; i < n; i++)
            b[i] = b[i + 1];

        n--;
        ans += m;
    }
    
    cout << ans;
    return 0;
}