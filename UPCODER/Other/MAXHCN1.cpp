#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 20 + 5;
const int MOD = 1e9 + 7;

int n, m, ans;
int c[MAXN][MAXN];

bool check(int top, int left, int bottom, int right) {
    for (int i = top; i <= bottom; i++) 
        for (int j = left; j <= right; j++)
            if (!c[i][j])   
                return false;
                
    return true;
}

int Try(int top, int left, int bottom, int right) {
    if (top > bottom || left > right)
        return 0;

    if (check(top, left, bottom, right))
        return (bottom - top + 1) * (right - left + 1);

    int res = 0;

    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (!c[i][j]) {
                res = max(res, Try(top, left, i - 1, right));
                res = max(res, Try(i + 1, left, bottom, right));
                res = max(res, Try(top, j + 1, bottom, right));
                res = max(res, Try(top, left, bottom, j - 1));
                return res;
            }
        }
    }

    return res;
}

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    ans = Try(1, 1, n, m);
    cout << ans;
    return 0;
}