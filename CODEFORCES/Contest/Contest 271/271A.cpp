#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

bool check(string n) {
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (n[i] == n[j])
                return false;
    return true;
}

signed main() {
    fastIO;
    int n;
    cin >> n;
    while (!check(to_string(++n)));
    cout << n;
    return 0;
}