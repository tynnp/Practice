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

int n, sum;

void solve() {
    cin >> n;
    sum = n*(n+1) >> 1;
    
    if (sum & 1) {
        cout << "NO";
        return;
    }
    
    cout << "YES" << endl;
    sum >>= 1;
    
    vector<int> a, b;
    for (int i = n; i >= 1; i--) {
        if (i <= sum) {
            a.push_back(i);
            sum -= i;
        } else 
            b.push_back(i);
    }
    
    cout << a.size() << endl;
    for (int x : a) 
        cout << x << " ";
    cout << endl;
    
    cout << b.size()  << endl;
    for (int x : b) 
        cout << x << " ";
}

signed main() {
    int t = 1;
    while (t--)
        solve();
    return 0;
}