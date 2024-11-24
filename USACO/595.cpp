#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("div7.in", "r", stdin)
#define out freopen("div7.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 50000 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int a[MAXN], idx[7];

signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = (a[i - 1] + x) % 7;
    }

    memset(idx, -1, sizeof(idx));
    for (int i = 1; i <= n; i++) {
        if (idx[a[i]] == -1)
            idx[a[i]] = i;
        else 
            ans = max(ans, i - idx[a[i]]);
    }
   
    cout << ans;
    return 0;
}