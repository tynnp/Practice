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

int n;
int arr[MAXN];
int dp[MAXN];

signed main() {
    fastIO;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
        
    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);
    for (int i = 3; i <= n; i++) 
        dp[i] = min(dp[i-1] + abs(arr[i-1] - arr[i]), dp[i-2] + abs(arr[i-2] - arr[i]));
    
    cout << dp[n];
    return 0;
}