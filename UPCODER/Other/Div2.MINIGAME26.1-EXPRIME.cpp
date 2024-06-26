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
vector<int> prime(MAXN, true);

void solve(int n) {
    if (n <= 1) {
        cout << "NO\n";
        return;
    }
    
    for (int a = 2; a*a <= n; a++) {
        if (prime[a]) {
            int b = 2, power = a*a;
            
            while (power <= n) {
                if (power == n) {
                    cout << "YES " << a << '^' << b << '=' << n << endl;
                    return;
                } 
                
                b++;
                power *= a;
            }
        }
    }
    
    cout << "NO\n";
}

signed main() {
    fastIO;
    
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= MAXN; i++)
        if (prime[i])
            for (int j = i*i; j <= MAXN; j += i)
                prime[j] = false;
    
    int n, t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        solve(n);
    }
    
    return 0;
}