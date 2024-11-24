#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("bcount.in", "r", stdin)
#define out freopen("bcount.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[MAXN], b[MAXN], c[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        c[i] = c[i - 1];

        int x;
        cin >> x;

        if (x == 1)  a[i]++;
        else if (x == 2) b[i]++;
        else c[i]++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << ' ' << b[r] - b[l - 1] << ' ' << c[r] - c[l - 1] << endl;
    }

    return 0;
}