#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
int n, ans(1);

signed main() {
    fastIO;
    
    cin >> n;
    for (int i = 2; i <= MAXN; i++) {
        if (n % i == 0) {
            ans *= i;
            while (n % i == 0)
                n /= i;
        }
    }
    
    ans *= sqrt(n) == (int) sqrt(n) ? sqrt(n) : n;
    cout << ans;
    return 0;
}