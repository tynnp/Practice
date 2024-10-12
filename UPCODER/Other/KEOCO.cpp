// Chua xong

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("KEOCO.inp", "r", stdin)
#define out freopen("KEOCO.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
vector<int> v(MAXN);

pair<int, int> Try(int idx, int sumA, int sumB) {
    if (idx == n)
        return {sumA, sumB};

    pair<int, int> a = Try(idx + 1, sumA + v[idx], sumB);
    pair<int, int> b = Try(idx + 1, sumA, sumB + v[idx]);

    if (abs(a.first - a.second) < abs(b.first - b.second))
        return a;
    return b;
}

signed main() {
    fastIO;
    inp;
    out;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    auto res = Try(0, 0, 0);
    cout << min(res.first, res.second) << ' ' << max(res.first, res.second);
    return 0;
}