#include <bits/stdc++.h>
using namespace std;

int n, ans(0), arr[1001];   // Lưu giá trị
vector<int> dp(1001, 1);    // Lưu độ dài

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >= 1; j--) 
            if (arr[j] <= arr[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
                
        if (dp[i] > ans) ans = dp[i];
    }
    
    cout << ans << endl;
    return 0;
}