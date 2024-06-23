#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e4 + 5;
const int MOD = 1e9 + 7;

int n, k, ans;
int arr[MAXN][MAXN];
int sum[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
            
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
     
    for (int i = 1; i <= n - k + 1; i++) 
        for (int j = 1; j <= n - k + 1; j++)
            ans = max(ans, sum[i+k-1][j+k-1] - sum[i-1][j+k-1] - sum[i+k-1][j-1] + sum[i-1][j-1]);
    
    cout << ans << endl;
    //cout << TIME;
    return 0;
} 