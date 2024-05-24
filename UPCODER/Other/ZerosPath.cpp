#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n, m, tmp;
bool zero = false;
int dp[MAXN][MAXN][2];
int arr[MAXN][MAXN][2];

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) {
                if (j == 1) dp[i][j][k] = arr[i][j][k];
                else dp[i][j][k] = dp[i][j-1][k] + arr[i][j][k];
                
            } else {
                if (j == 1) dp[i][j][k] = dp[i-1][j][k] + arr[i][j][k];
                else dp[i][j][k] = min(dp[i-1][j][k], dp[i][j-1][k]) + arr[i][j][k];
            }   
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> tmp;
            if (tmp == 0) zero = true;
            
            else {
                while (tmp % 2 == 0) 
                    arr[i][j][0]++,
                    tmp /= 2;
                    
                while (tmp % 5 == 0)
                    arr[i][j][1]++,
                    tmp /= 5;
            }
        }
    }
    
    Try(0), Try(1);
    
    if (zero && dp[n][m][0] && dp[n][m][1]) cout << 1;
    else cout << min(dp[n][m][0], dp[n][m][1]);
    return 0;
}