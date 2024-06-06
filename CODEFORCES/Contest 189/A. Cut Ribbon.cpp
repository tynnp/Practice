#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a(3);
vector<long long> dp(10000, 0);

int main() {
    cin >> n;
    for (long long &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    dp[a[0]] = dp[a[1]] = dp[a[2]] = 1;
    
    for (long long i = a[0] + 1; i <= n; i++) 
        for (long long j = 0; j < 3; j++) 
            if (i >= a[j] && dp[i - a[j]] > 0)
                dp[i] = max(dp[i], dp[i - a[j]] + 1);
            
    cout << dp[n];
    return 0;
}
