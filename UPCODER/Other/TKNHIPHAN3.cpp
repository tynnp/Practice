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

const int MAXN = 1e4 + 5;
const int MOD = 1e9 + 7;

int n, x, pos[MAXN];
int a[MAXN];

int search(int a[], int n, int x) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x) 
            l = mid + 1;
        else 
            r = mid - 1;
    }

    return -1;
}

signed main() {
    fastIO;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    sort(a, a + n);
    int idx = search(a, n, x);
    
    if (idx != -1)
        cout << pos[a[idx]];
    else 
        cout << -1;
    
    return 0;
}