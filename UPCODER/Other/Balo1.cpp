#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    
    vector<int> a(n+1);
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + a[i]);
        }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= w; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][w] << endl;
    
    int maxW = dp[n][w];
    vector<int> res;
    
    for (int i = n; i > 0; i--) 
        if (dp[i][maxW] != dp[i-1][maxW]) {
            res.push_back(i-1);
            maxW -= a[i];
        }
    
    reverse(res.begin(), res.end());
    for (int x : res) cout << x << " ";
    return 0;
}