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

int len(int k) {
    if (k == -1) 
        return 0;
  
    int x = len(k - 1);
    return 2 * x + k + 3;
}

char find(int n, int k) {
    if (n > len(k))
        return find(n, k+1);
    
    if (n <= len(k-1))
        return find(n, k-1);
    
    n -= len(k - 1);
    if (n <= k + 3) 
        return n == 1 ? 'b' : 'o';
    
    n -= k + 3;
    return find(n, k-1);
}

signed main() {
    fastIO;
    int n, t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        cout << find(n, 0) << endl;
    }
    
    return 0;
}