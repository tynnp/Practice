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

signed main() {
    fastIO;
    int n;
    vector<int> v;
    cin >> n;

    for (int i = 6; i <= n; i++)
        if (i % 6 == 0) 
            v.push_back(i);
        
    cout << v.size() << endl;
    for (int x : v) cout << x << " ";
    return 0;
}