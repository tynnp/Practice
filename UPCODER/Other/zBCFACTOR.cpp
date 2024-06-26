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
    int n, cnt, k = 2;
    bool check = false;
    cin >> n;
    
    while (n > 1) {
        cnt = 0;
        
        while (n % k == 0) {
            cnt++;
            n /= k;
        }
        
        if (cnt) {
            if (check) cout << '*';
            cout << k << '^' << cnt;
            check = true;
        }
        k += k == 2 ? 1 : 2;
    }
    
    return 0;
}