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

void solve() {
    string str;
    getline(cin, str);
    
    for (char &c : str)
        if (!(c >= 'a' && c <= 'z'))
            c = ' ';

    string s;
    vector<int> v;
    stringstream ss(str);
    
    while (ss >> s) 
        v.push_back(s.size());

    // for (int x : v)
    //     cout << x << ' ';
    // cout << endl; 

    int cnt = 1, ans = 1;

    for (int i = 1; i < v.size(); i++) {
        if (v[i-1] == v[i]) cnt++;
        else cnt = 1;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
 
signed main() {
    fastIO;
    int t;
    cin >> t;
    cin.ignore();

    while (t--) 
        solve();
    
    return 0;
}