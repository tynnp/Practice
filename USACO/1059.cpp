#include <iostream>
#include <algorithm>
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
    int a[7];

    for (int &x : a) 
        cin >> x;

    sort(a, a + 7);

    cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[1] - a[0];
    return 0;
}