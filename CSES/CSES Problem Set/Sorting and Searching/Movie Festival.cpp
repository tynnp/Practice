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

int n, ans;
vector<pair<int, int>> v;

void solve() {
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end(), [] (auto a, auto b) {
        return a.second < b.second;
    });
    
    int timeEnd = 0;
    for (auto x : v) {
        if (x.first >= timeEnd) {
            ans++;
            timeEnd = x.second;
        }
    }
    
    cout << ans;
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