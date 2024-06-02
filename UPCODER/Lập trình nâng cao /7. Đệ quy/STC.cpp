#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
    fast;
    
    int n;
    cin >> n;
    
    // dp[i][j] số cách xây cầu thang với i viên max j bước
    vector<vll> dp(n+1, vll(n+1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 0; k < j; k++)
                dp[i][j] += dp[i - j][k];
                
    ll ans(-1);
    for (int i = 1; i <= n; i++)
        ans += dp[n][i];
    
    cout << ans;
    return 0;
}

