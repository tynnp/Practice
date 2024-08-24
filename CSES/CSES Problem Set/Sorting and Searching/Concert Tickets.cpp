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

int n, m;
multiset<int> s;

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        auto it = s.upper_bound(tmp);
        
        if (it == s.begin())
            cout << -1 << endl;
        else {
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
}

signed main() {
    fastIO;
    int t;
    //cin >> t;
    t = 1;
    
    while (t--)
        solve();
    return 0;
}