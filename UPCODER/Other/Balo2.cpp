#include <bits/stdc++.h>
using namespace std;

int n, w, m;
int a[1001], c[1001];
int dp[1001][1001] = {{0}};
list<int> lst;

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
        
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + c[i]);
        }
    
    m = w;
    for (int i = n; i > 0; i--) 
        if (dp[i][m] != dp[i-1][m]) 
            lst.push_front(1),
            m -= a[i];
        else 
            lst.push_front(0);
    
    cout << dp[n][w] << endl;
    for (auto x : lst) cout << x << " ";
    return 0;
}