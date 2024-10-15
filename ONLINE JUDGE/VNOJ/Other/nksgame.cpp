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
const int INF = 1e9;

int n, ans = INT_MAX;
int b[MAXN], c[MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(b, b + n);
    sort(c, c + n);

    int i = 0, j = n - 1;
    while (i < n) {
        ans = min(ans, abs(b[i] + c[j]));
        
        while (j > 0 && abs(b[i] + c[j-1]) <= abs(b[i] + c[j])) {
            ans = min(ans, abs(b[i] + c[j-1]));
            j--;
        }

        i++;
    }
    
    cout << ans;
    return 0;
}