#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
   
    int arr[n];
    for (int &x : arr) cin >> x;
    
    vector<int> dp(101, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    
    for(int i = 2; i < n; i++)
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
        
    cout << dp[n-1];
    return 0;
}