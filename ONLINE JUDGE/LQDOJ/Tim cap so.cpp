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

int n, x;

signed main() {
    fastIO;
    cin >> n >> x;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    int i = 0, j = n - 1;
    while (i < j) {
        if (v[i] + v[j] == x) {
            cout << i+1 << " " << j+1;
            break;
        }
        
        if (v[i] + v[j] < x) i++;
        else j--;
    }
    
    if (i >= j)
        cout << "No solution";
    
    return 0;
}