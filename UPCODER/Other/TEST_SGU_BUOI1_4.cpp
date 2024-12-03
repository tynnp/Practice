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

int n, totalDiv, primeDiv;
map<int, int> fac;

signed main() {
    fastIO;
    cin >> n;

    while (n % 2 == 0) {
        fac[2]++;
        n >>= 1;
    }

    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            fac[i]++;
            n /= i;
        }
    }

    if (n > 2) 
        fac[n]++;
    
    totalDiv = 1;
    primeDiv = fac.size();

    for (auto &f : fac) 
        totalDiv *= (f.second + 1); 

    cout << primeDiv << ' ' << totalDiv;
    return 0;
}