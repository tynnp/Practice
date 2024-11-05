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

bool binary_search(int &x) {
    int l = n;
    int r = 2*n - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (s[mid] == x)
            return true;

        if (s[mid] < x)
            l = mid + 1;
        else 
            r = mid - 1;
    }

    return false;
}

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }

    sort(s, s + 2*n);

    for (int i = 0; i < 2*n; i++) 
        if (binary_search(a[i]))
            cout << a[i] << ' ';
    
    return 0;
}