#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 200;
const int MOD = 1e9 + 7;

int n, m, ans;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) 
        cin >> a[i];
        
    for (int i = 0; i < m; i++) 
        cin >> b[i];
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
    ans = dp[n][m];
    int i = n, j = m;
    list<int> v, x, y;
    
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            v.push_front(a[i-1]);
            x.push_front(i--);
            y.push_front(j--);
        }
        else if (dp[i-1][j] >= dp[i][j-1]) i--;
        else j--;
    }
    
        
    cout << ans << endl;
    
    for (int k : v) 
        cout << k << " "; 
    cout << endl;
    
    for (int k : x) 
        cout << k << " ";
    cout << endl;
    
    for (int k : y)
        cout << k << " ";
    return 0;
} 