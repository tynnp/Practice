#include <bits/stdc++.h>
using namespace std;

int n, w;
const int MAXN = 1e5 + 1;
int dp[1001][MAXN] = {{0}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w;
    vector<int> a(n + 1), v(n + 1);
    
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    for (int i = 1; i <= n; i++) 
        cin >> v[i];

    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j - a[i]] + v[i]);
        }
        
    cout << dp[n][w];
    return 0;
}