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

signed main() {
    fastIO;
    int n;
    cin >> n;
    
    int a[n], b[n];
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    sort(a, a + n);
    sort(b, b + n);
    
    int ans = INT_MAX, i = 0, j = n - 1;
    
    while (i < n) {
        ans = min(ans, abs(a[i] + b[j]));
        while (j > 0 && abs(a[i] + b[j-1]) <= abs(a[i] + b[j])) {
            ans = min(ans, abs(a[i] + b[j-1]));
            j--;
        }
        
        i++;
    }
    
    cout << ans;
    return 0;
}