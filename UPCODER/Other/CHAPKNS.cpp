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

int n, k;
string s, ans("");

void Try(int x, int idx) {
    if (x == k && idx < n) {
        cout << ans << endl; 
        return;
    }
    
    for (int i = idx; i < n; i++) {
        ans += s[i];
        x += 1;
        
        Try(x, i);
        
        ans.pop_back();
        x -= 1;
    }
}

signed main() {
    fastIO;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    //cout << s << endl;

    for (int i = 0; i < s.size(); i++) {
        //cout << s[i] << endl;
        ans += s[i];
        Try(1, i);
        ans.pop_back();
    }
    
    return 0;
}