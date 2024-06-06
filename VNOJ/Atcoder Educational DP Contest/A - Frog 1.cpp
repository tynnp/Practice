#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    
    vector<ll> h(n),dp(n+1, 0);
    for (auto &x : h) cin >> x;
    
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i <  n; i++)
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    
    cout << dp[n-1];
    return 0;
}