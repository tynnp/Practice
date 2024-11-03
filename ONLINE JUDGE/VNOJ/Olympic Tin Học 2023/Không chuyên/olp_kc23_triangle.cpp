#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int unsigned long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int s, d, r, u, v;

signed main() {
    fastIO;
    cin >> u >> v;
    s = u*u + v*v;
    d = s / 4;
    r = s % 4;

    cout << d << '.';

    if (r == 0) 
        cout << "00";

    else if (r == 1) 
        cout << "25";

    else if (r == 2) 
        cout << "50";

    else 
        cout << "75";

    return 0;
}