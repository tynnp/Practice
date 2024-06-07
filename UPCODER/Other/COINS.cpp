#include <bits/stdc++.h>
using namespace std;

ifstream fin("COINS.INP");
ofstream fout("COINS.OUT");

int n, m;
vector<int> v(1001);
vector<int> dp(1000001, INT_MAX);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
        
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[j] <= i && dp[i - v[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }
    
    fout << (dp[m] == INT_MAX ? -1 : dp[m]);
    return 0;
}
