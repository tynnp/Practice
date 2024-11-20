#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("teleport.in", "r", stdin)
#define out freopen("teleport.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << min(abs(a - b), min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x)));
    return 0;
}