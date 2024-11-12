#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int MAXN = 5e6 + 5;
const int MOD = 1e9 + 7;
 
int n, dp[MAXN];
 
signed main() {
    fastIO;
    cin >> n;
 
    int sum = n * (n + 1) >> 1;
    if (sum & 1) {
        cout << 0;
        return 0;
    }
 
    int mid = sum >> 1;
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) 
        for (int j = mid; j >= i; j--) 
            (dp[j] += dp[j - i]) %= MOD;
    
    cout << dp[mid] * 500000004 % MOD;
    return 0;
}