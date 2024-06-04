#include <bits/stdc++.h>
using namespace std;

int n, w, m;
int a[101], c[101];
int dp[101][101] = {{0}};
list<int> lst;

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
        
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= w; j++) {   
            dp[i][j] = dp[i-1][j];
            if (c[i] <= j)   
                dp[i][j] = max(dp[i][j], dp[i-1][j - c[i]] + a[i]);
        }
        
    m = w;
    for (int i = n; i > 0; i--) 
        if (dp[i][m] != dp[i-1][m]) {
            lst.push_front(i);
            m -= c[i];
        }
    
    cout << dp[n][w] << endl;
    cout << lst.size() << " ";
    for (auto &x : lst) cout << x << " ";
    return 0;
}