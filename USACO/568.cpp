#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("speeding.in", "r", stdin)
#define out freopen("speeding.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 100 + 5;
const int MOD = 1e9 + 7;

int n, m, ans;
int a[MAXN], b[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n >> m;

    int k = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;

        for (int j = k; j < k + x; j++)
            a[j] = y;
        k += x;
    }
  
    k = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;

        for (int j = k; j < k + x; j++)
            b[j] = y;
        k += x;
    }

    for (int i = 0; i < 100; i++)
        ans = max(ans, b[i] - a[i]);

    cout << ans;
    return 0;
}