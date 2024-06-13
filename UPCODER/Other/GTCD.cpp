#include <bits/stdc++.h>
using namespace std;

int n, t;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
vector<long long> dp(MAXN, 1);


int main() {
    for (int i = 2; i < MAXN; i++)
        dp[i] = dp[i - 1] * i % MOD;
        
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    
    return 0;
}