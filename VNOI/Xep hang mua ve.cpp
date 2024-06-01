#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int t[n], r[n-1], dp[n+1] = {0};
    for (int &x : t) cin >> x;
    for (int &x : r) cin >> x;
    
    dp[0] = t[0];
    dp[1] = min(dp[0] + t[1], r[0]);
    
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1] + t[i], dp[i-2] + r[i-1]);
        
    cout << dp[n-1];
    return 0;
}