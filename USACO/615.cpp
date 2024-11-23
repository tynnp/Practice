#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("pails.in", "r", stdin)
#define out freopen("pails.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int x, y, m;
    cin >> x >> y >> m;

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (x * i > m)
            break;

        for (int j = 0; j <= m; j++) {
            int z = x*i + y*j;

            if (z > m)
                break;

            ans = max(ans, z);
        }
    }
    
    cout << ans;
    return 0;
}