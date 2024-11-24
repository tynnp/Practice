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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Customer {
    int time, tus;
};

int n, sum, ans;
vector<Customer> a;
multiset<int> res;

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, 1});
        a.push_back({y, -1});
    }
    
    sort(a.begin(), a.end(), [] (Customer &x, Customer &y) {
        return x.time < y.time;
    });

    for (Customer x : a) {
        sum += x.tus;
        ans = max(ans, sum);
    }
    
    cout << ans;
    return 0;
}