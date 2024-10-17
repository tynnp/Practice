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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, ans;
vector<int> v, len;

signed main() {
    fastIO;
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1])
            cnt++;
        else {
            len.push_back(cnt);
            cnt = 1;
        }
    }
    len.push_back(cnt);

    for (int i = 1; i < len.size(); i++) 
        ans = max(ans, 2 * min(len[i], len[i-1]));

    cout << ans;
    return 0;
}