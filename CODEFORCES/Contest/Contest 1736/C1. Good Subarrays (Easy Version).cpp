#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, ans(0);
        cin >> n;

        vector<int> v(n), dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            dp[i + 1] = min(dp[i] + 1, v[i]);
            ans += dp[i + 1];
        }

        cout << ans << endl;
    }

    return 0;
}