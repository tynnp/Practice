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

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> v;

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back({x , i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int x = i + 1, y = n - 1;
        int sum = v[i].first;

        while (x < y) {
            int k = v[x].first + v[y].first;

            if (sum + k == m) {
                cout << v[i].second << ' ' << v[x].second << ' ' << v[y].second;
                return 0;
            }

            if (sum + k > m)
                y--;
            else 
                x++;
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}