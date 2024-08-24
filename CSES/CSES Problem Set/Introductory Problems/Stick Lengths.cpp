#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, ans;

void solve() {
    cin >> n;
    vector<int> v(n);
    
    for (int &x : v) 
        cin >> x;
    
    sort(v.begin(), v.end());
    
    // Tính trung vị dãy số
    int mid = ((n + 1) / 2);
    int a = v[mid - 1];
    
    for (int x : v) 
        ans += abs(x - a);
    cout << ans;
}

signed main() {
    int t = 1;
    while (t--)
        solve();
    return 0;
}