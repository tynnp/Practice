#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

string n, s[2];
void solve() {
    cin >> n;
    for (char c : n) 
        s[(c - '0') & 1] += c;

    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());

    int i = s[0].size()-1, j = s[1].size()-1;
    string ans = "";

    while (i >= 0 || j >= 0) {
        if (i < 0) {    
            ans += s[1][j--];
            continue;
        }

        if (j < 0) {
            ans += s[0][i--];
            continue;
        }

        if (s[0][i] < s[1][j]) 
            ans += s[0][i--];
        else 
            ans += s[1][j--];
    }

    cout << ans << endl;
    s[0].clear();
    s[1].clear();
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}