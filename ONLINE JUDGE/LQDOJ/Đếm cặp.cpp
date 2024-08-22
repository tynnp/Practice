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

int n, x, ans;
map<int, int> m;

signed main() {
    fastIO;
    cin >> n >> x;
    int tmp;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        m[tmp]++;
    }
    
    for (auto e : m) {
        int u = e.first;
        int v = x - u;
        if (u > v) break;
        
        int fx = m[u];
        int fy = m[v];
        
        if (u == v) 
            ans += fx * (fx-1) / 2;
        else 
            ans += fx * fy;
    }
    
    cout << ans;
    return 0;
}