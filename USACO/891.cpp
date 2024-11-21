#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("shell.in", "r", stdin)
#define out freopen("shell.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, cnt[4];
int x[] = {0, 1, 2, 3};

signed main() {
    fastIO; inp; out;
    cin >> n;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        swap(x[a], x[b]);
        cnt[x[c]]++;
    }
    
    cout << max({cnt[1], cnt[2], cnt[3]});
    return 0;
}