#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("blist.in", "r", stdin)
#define out freopen("blist.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1005 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int cow[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int s, t, b;
        cin >> s >> t >> b;

        for (int j = s; j < t; j++)
            cow[j] += b;
    }

    for (int i = 1; i < MAXN; i++)
        ans = max(ans, cow[i]);
    
    cout << ans;
    return 0;
}