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
int a, b, ans;

bool snt(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return n > 1;
}

bool doiXung(int n) {
    string s = to_string(n);
    int i = 0, j = s.size() - 1;
    
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }

    return true;
}

signed main() {
    fastIO;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
        if (snt(i) && doiXung(i))
            ans++;
    
    cout << ans;
    return 0;
}