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

int n, cnt, ans;
int a[MAXN];
map<int, int> m;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    int i = 0, j = 0;
    while (j < n) {
        m[a[j]]++;
        
        if (m[a[j]] == 1) 
            cnt++;
        else {
            while (i < j && m[a[j]] > 1) {
                if (m[a[i]] == 1) cnt--;
                m[a[i++]]--;
            }
        }
        
        j++;
        ans = max(ans, cnt);
    }
    
    cout << ans;
}

signed main() {
    fastIO;
    solve();
    return 0;
}