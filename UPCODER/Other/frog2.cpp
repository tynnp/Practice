#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAXN = 1e5 + 1;
vector<int> a(MAXN), dp(MAXN, INT_MAX);

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    dp[1] = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = max(1, i - k); j < i; j++)
            dp[i] = min(dp[i], abs(a[i] - a[j]) + dp[j]);
            
    cout << dp[n];
    return 0;
}