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

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int a[MAXN], cnt[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int i = 1, j = 1;
    while (j <= n) {
        cnt[a[j]]++;

        while (cnt[a[j]] > 2) {
            cnt[a[i]]--;
            i++;
        }

        ans += j - i + 1;

        j++;
    }
    
    cout << ans;
    return 0;
}