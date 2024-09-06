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

int n, s;
int a[MAXN];
bool dp[MAXN];
vector<int> res;

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    dp[0] = true;
    for (int i = 0; i < n; i++) 
        for (int j = s; j >= a[i]; j--) 
            if (!dp[j])
                dp[j] = dp[j - a[i]];
    
    for (int i = 1; i <= s; i++)
        if (dp[i])
            res.push_back(i);
            
    cout << res.size() << endl;
    for (int x : res)
        cout << x << " ";
    
    return 0;
}