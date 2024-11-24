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

signed main() {
    fastIO;
    int n;
    cin >> n;
    int sum = n * (n + 1) >> 1;
    
    if (sum & 1) {
        cout << "NO";
        return 0;
    }

    sum >>= 1;
    vector<int> a, b;

    for (int i = n; i >= 1; i--) {
        if (sum >= i) {
            a.push_back(i);
            sum -= i;
        } else 
            b.push_back(i);
    }


    cout << "YES\n";

    cout << a.size() << endl;
    for (int x : a)     
        cout << x << ' ';
    cout << endl;

    cout << b.size() << endl;
    for (int x : b)
        cout << x << ' ';
    
    return 0;
}