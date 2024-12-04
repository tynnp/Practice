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
    string cur;
    int t;

    cin >> cur >> t;
    int hh = stoi(cur.substr(0, 2));
    int mm = stoi(cur.substr(3, 2));
    int ss = stoi(cur.substr(6, 2));

    int total = hh * 3600 + mm * 60 + ss + t;
    
    hh = (total / 3600) % 24;
    mm = (total / 60) % 60;
    ss = total % 60;

    cout << setw(2) << setfill('0') << hh << ":";
    cout << setw(2) << setfill('0') << mm << ":";
    cout << setw(2) << setfill('0') << ss; 

    return 0;
}