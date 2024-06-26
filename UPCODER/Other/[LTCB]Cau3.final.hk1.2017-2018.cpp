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

int t, a, b, m, n, ans;
vector<int> prime(MAXN, true);

signed main() {
    fastIO;
    
    prime[1] = prime[0] = false;
    for (int i = 2; i*i <= MAXN; i++)
        if (prime[i])
            for (int j = i*i; j <= MAXN; j += i)
                prime[j] = false;
     
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> a >> b >> m >> n;
        for (int i = a; i <= b; i++)
            if (prime[i] && i % m == n)
                ans += i;
        cout << ans << endl;
    }
    
    return 0;
}