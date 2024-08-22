#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int t;
string s;

void solve() {
    cin >> s;
    vector<int> a, b, ans;
    
    for (char c : s) {
        if (c & 1) b.push_back(c - '0');
        else a.push_back(c - '0');
    }
    
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (j == b.size() || (i < a.size() && a[i] <= b[j]))
            ans.push_back(a[i++]);
        else 
            ans.push_back(b[j++]);
    }
    
    for (int x : ans) 
        cout << x;
    cout << endl;
}

signed main() {
    fastIO;
    cin >> t;
    while (t--)
        solve();
    return 0;
}