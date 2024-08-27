#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m, ans;
int a[MAXN];

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) 
        cin >> a[i];
        
    sort(a, a + n);
  
    int i = 0, j = n-1;
    while (i <= j) {
        if (a[i] + a[j] <= m) 
            i++, j--;
        else 
            j--;
        ans++;
    }
    
    cout << ans;
}

signed main() {
    fastIO;
    solve();
    return 0;
}