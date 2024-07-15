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

int odd;
string s, ans;
map<char, int> m;
pair<char, int> p;

void solve() {
    cin >> s;
    for (char c : s) m[c]++;

    for (auto x : m) {
        if (x.second % 2) {
            odd++;
            p = x;
        } else 
            ans.insert(ans.size()/2, x.second, x.first);
            
        if (odd > 1) {
            cout << "NO SOLUTION";
            return;
        }
    }
    
    if (odd) ans.insert(ans.size()/2, p.second, p.first);
    cout << ans;
}

signed main() {
    fastIO;
    solve();
    return 0;
}