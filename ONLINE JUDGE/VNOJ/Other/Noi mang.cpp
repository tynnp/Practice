#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    
    vector<ll> d(n + 1, 10000000), dp(n + 1, 0);
    for (int i = 1; i < n; i++)
        cin >> d[i];
    
    dp[1] = d[1];
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-2] + d[i-1], dp[i-1] + d[i]);
    
    cout << dp[n];
    return 0;
}