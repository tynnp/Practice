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

int n, s;
vector<pair<int, int>> v;

void solve() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }
    
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    
    while (i < j) {
        int x = v[i].first + v[j].first;
        if (x == s) {
            cout << v[i].second << " " << v[j].second;
            return;
        }
        
        if (x > s) j--;
        else i++;
    }
    
    cout << "IMPOSSIBLE";
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