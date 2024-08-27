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
 
int n, m, k;
int a[MAXN], b[MAXN];
 
void solve() {
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];
        
    sort(a, a + n);
    sort(b, b + m);
    
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            i++, j++, ans++;
        } else {
            if (a[i] - b[j] > k) j++;
            else i++;
        }
    }
    
    cout << ans;
}
 
signed main() {
    fastIO;
    solve();
    return 0;
}
