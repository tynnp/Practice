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

int n, h, ans(INT_MAX);
vector<int> a, b;
vector<int> cnt(MAXN, 0);

signed main() {
    fastIO;
    
    cin >> n >> h;
    for (int i = 0; i < n/2; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i = 1; i <= h; i++) {
        int sum = 0;
        sum += a.end() - lower_bound(a.begin(), a.end(), i);
        sum += b.end() - upper_bound(b.begin(), b.end(), h - i);
        ans = min(ans, sum);
        cnt[sum]++;
    }
    
    cout << ans << " " << cnt[ans];
    return 0;
}