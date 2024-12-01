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

bool doiXung(const string &s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }

    return true;
}

string s;
set<string> ans;

signed main() {
    fastIO;
    cin >> s;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            string sub = s.substr(j, i);
            if (doiXung(sub))
                ans.insert(sub);
        }
    }
    
    cout << ans.size();
    return 0;
}