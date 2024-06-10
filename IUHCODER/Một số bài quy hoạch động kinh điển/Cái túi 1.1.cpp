#include <bits/stdc++.h>
using namespace std;

int n, w;
const int MAXN = 1e5 + 1;
long long dp[101][MAXN] = {{0}};

int main() {
    cin >> n >> w;
    vector<int> a(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i] >> v[i];

    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j - a[i]] + v[i]);
        }
        
    cout << dp[n][w];
    return 0;
}