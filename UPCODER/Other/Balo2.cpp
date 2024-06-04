#include <bits/stdc++.h>
using namespace std;

int n, w;
int a[1001], c[1001];
vector<vector<int>> dp(1001, vector<int>(1001, 0));
list<int> lst;

int main() {
    cin >> n >> w;
    
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
        
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j && dp[i][j] < dp[i-1][j-a[i]] + c[i])
                dp[i][j] = dp[i-1][j-a[i]] + c[i];
        }
    }
    
    int maxW = w;
    for (int i = n; i > 0; i--) {
        if (dp[i][maxW] != dp[i-1][maxW]) {
            lst.push_front(1);
            maxW -= a[i];
        } else 
            lst.push_front(0);
    }
    
    cout << dp[n][w] << endl;
    for (auto x : lst) cout << x << " ";
    return 0;
}