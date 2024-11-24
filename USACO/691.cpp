#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("hps.in", "r", stdin)
#define out freopen("hps.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int h[MAXN], p[MAXN], s[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1];
        p[i] = p[i - 1];
        s[i] = s[i - 1];

        char c;
        cin >> c;

        if (c == 'H')
            p[i]++;
        else if (c == 'P')
            s[i]++;
        else    
            h[i]++;
    }

    for (int i = 1; i <= n; i++) {
        int x = max({h[i], p[i], s[i]});
        int y = max({h[n] - h[i], p[n] - p[i], s[n] - s[i]});
        ans = max(ans, x + y);
    }

    cout << ans;
    return 0;
}