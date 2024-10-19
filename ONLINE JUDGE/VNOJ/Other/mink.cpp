#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 17000 + 5;
const int MOD = 1e9 + 7;

int n, k, a[MAXN];
deque<int> dq;

void solve() {
    cin >> n >> k;
    dq.clear();

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        if (i >= k)
            cout << a[dq.front()] << endl;
    }
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}