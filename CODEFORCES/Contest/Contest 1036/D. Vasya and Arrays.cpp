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

int n, m, sa, sb, ans;

signed main() {
    fastIO;
    
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    cin >> m;
    vector<int> b(m);
    for (int &x : b) cin >> x;
    
    int i = 0, j = 0;
    sa = a[i], sb = b[i];
    
    while (i < n && j < m) {
        if (sa == sb) {
            ans++;
            sa = a[++i];
            sb = b[++j];
            continue;
        }
        
        if (sa < sb) sa += a[++i];
        else sb += b[++j];
    }
    
    if (i != n || j != m) 
        cout << -1;
    else 
        cout << ans;
    
    return 0;
}