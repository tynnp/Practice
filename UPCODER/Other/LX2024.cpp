#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int r, m, n;
vector<pair<int, int>> a, b;

signed main() {
    fastIO;
    cin >> r >> m >> n;
    
    a.resize(m);
    b.resize(n);
    
    for (int i = 0; i < m; i++) 
        cin >> a[i].first;
  
    for (int i = 0; i < m; i++) 
        cin >> a[i].second;
    
    for (int i = 0; i < n; i++)
        cin >> b[i].first;
    
    for (int i = 0; i < n; i++)
        cin >> b[i].second;
        
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> sumA(m + 1, 0);
    vector<int> sumB(n + 1, 0);
    
    for (int i = 0; i < m; i++) 
        sumA[i + 1] = sumA[i] + a[i].second;
    
    for (int i = 0; i < n; i++) 
        sumB[i + 1] = sumB[i] + b[i].second;
    
    int ans = 0;
    for (int x = 0; x <= r; x++) {
        auto itr = lower_bound(a.begin(), a.end(), make_pair(x, LLONG_MIN));
        int cntA = distance(a.begin(), itr);
        int sumR = sumA[m] - sumA[cntA];
        
        auto itl = lower_bound(b.begin(), b.end(), make_pair(r - x, LLONG_MIN));
        int cntB = distance(b.begin(), itl);
        int sumL = sumB[n] - sumB[cntB];
        
        ans = max(ans, sumR + sumL);
    }
    
    cout << ans;
    return 0;
}
