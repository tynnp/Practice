#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, h, ans = INT_MAX;
vector<int> a, b;
int cnt[MAXN];

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