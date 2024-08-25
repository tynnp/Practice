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

int n, x;
map<int, pair<int, int>> m;

void solve() {
    cin >> n >> x;
    vector<int> v(n);
    for (int &e : v) cin >> e;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            m[v[i] + v[j]] = {i, j};
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int e = x - v[i] - v[j];
            if (m.count(e)) {
                pair<int, int> p = m[e];
                if (j < p.first) {
                    cout << i+1 << " " << j+1 << " " << p.first+1 << " " << p.second+1;
                    return;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE";
}

signed main() {
    int t = 1;
    while (t--)
        solve();
    return 0;
}