#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 3000 + 5;
const int MOD = 1e9 + 7;

int n;
vector<int> res;

bool prime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 2; i <= n; ++i) {
        int cnt = 0;
        
        for (int j = 2; j <= i; ++j) {
            if (i % j == 0 && prime(j)) {
                cnt++;
                if (cnt > 2) break;
            }
        }
        
        if (cnt == 2) 
            res.push_back(i);
    }

    cout << res.size() << endl;
    for (int x : res) cout << x << " ";
    return 0;
}