#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("diamond.in", "r", stdin)
#define out freopen("diamond.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e4 + 5;
const int MOD = 1e9 + 7;

int n, k, ans;
int a[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) { 
        int cnt = 0;

        for (int j = 1; j <= n; j++)
            if (a[i] <= a[j] && a[j] <= a[i] + k)
                cnt += 1;

        ans = max(ans, cnt);
    }
    
    cout << ans;
    return 0;
}