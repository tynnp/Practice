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

void binary(int n) {
    cout << "NO ";
    stack<int> s;
    
    while (n) {
        s.push(n % 2);
        n /= 2;
    }
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    
    cout << endl;
}

void power(int n) {
    if (n == 0) {
        cout << "NO " << 0;
        return;
    }
    
    cout << "YES ";
    int p = 0;
    
    while (n > 1) {
        p += 1;
        n /= 2;
    }
    
    cout << 2 << '^' << p << endl;
}

signed main() {
    fastIO;
    int n, t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        if ((n & (n - 1)) == 0) power(n);
        else binary(n);
    }
    
    return 0;
}