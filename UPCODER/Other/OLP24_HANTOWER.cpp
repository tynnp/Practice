#include <bits/stdc++.h>
using namespace std;

const int maxN = 31;
const int maxM = 31;
long long dp[maxN][maxM] = {{LLONG_MAX}};

void solve(int n, int m) {
    dp[1][3] = 1;
    for (int i = 2; i <= n; i++)
        dp[i][3] = 2 * dp[i-1][3] + 1;
    
    for (int j = 4; j <= m; j++) {
        dp[1][j] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][j] = 2 * dp[1][j] + dp[i-1][j-1];
            for (int k = 2; k < i; k++)
                dp[i][j] = min(dp[i][j], 2 * dp[k][j] + dp[i-k][j-1]);
        }
    }
    
    cout << dp[n][m];
}

int main() {
    int n, m;
    while (cin >> n >> m) 
        solve(n, m);
    return 0;
}