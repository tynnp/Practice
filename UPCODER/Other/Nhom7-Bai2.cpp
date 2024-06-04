#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v(1001), dp(1001, 1);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
        
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= 1; j--)
            if (v[j] < v[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
    }
    
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}