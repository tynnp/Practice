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
const int INF = 1e9;

signed main() {
    fastIO;
    string n;
    cin >> n;

    string min = n;
    sort(min.begin(), min.end());

    string max = n;
    sort(max.begin(), max.end(), greater<char>());

    size_t pos = min.find_first_not_of('0');
    if (pos != string::npos && pos != 0)
        swap(min[0], min[pos]); 

    cout << max << endl << min;
    return 0;
}