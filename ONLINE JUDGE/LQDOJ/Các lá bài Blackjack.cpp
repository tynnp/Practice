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

int n, m, ans;

signed main() {
    fastIO;
    cin >> n >> m;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1, k = n-1;
        
        while (j < k) {
            int x = v[i] + v[j] + v[k];
            
            if (x <= m) {
                ans = max(ans, x);
                j++;
            } else k--;
        }
    }
    
    cout << ans;
    return 0;
}