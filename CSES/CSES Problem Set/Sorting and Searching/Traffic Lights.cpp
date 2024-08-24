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

int x, n;
multiset<int> s, ans;

void solve() {
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    ans.insert(x);
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        auto right = s.upper_bound(a);
        auto left = prev(right);
        
        ans.erase(ans.find(*right - *left));
        ans.insert(a - *left);
        ans.insert(*right - a);
        s.insert(a);
        
        cout << *ans.rbegin() << " ";
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