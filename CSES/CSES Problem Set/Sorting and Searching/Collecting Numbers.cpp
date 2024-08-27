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

int n, ans = 1;
int a[MAXN], pos[MAXN];

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    sort(a, a + n);
    
    for (int i = 1; i < n; i++) {
        if (pos[a[i-1]] > pos[a[i]])
            ans++;
    }
    
    cout << ans;
    return 0;
}