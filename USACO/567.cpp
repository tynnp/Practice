#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("paint.in", "r", stdin)
#define out freopen("paint.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int a, b, c, d, ans;
bool check[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> a >> b >> c >> d;

    for (int i = a; i < b; i++)
        check[i] = true;

    for (int i = c; i < d; i++)
        check[i] = true;

    for (int i = 0; i < MAXN; i++)
        ans += check[i];
    
    cout << ans;
    return 0;
}