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

int n, ans;
int c[MAXN][MAXN];

bool check(int row, int col) {
    for (int i = 1; i <= row; i++)
        if (c[i][col])
            return false;

    for (int i = row, j = col; i >= 1 && j >= 1; i--, j--)
        if (c[i][j])
            return false;

    for (int i = row, j = col; i >= 1 && j <= n; i--, j++)
        if (c[i][j])
            return false;

    return true;
}

void Try(int row) {
    if (row > n) {
        ans++;
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (check(row, col)) {
            c[row][col] = 1;
            Try(row + 1);
            c[row][col] = 0;
        }
    }
}

signed main() {
    fastIO;
    cin >> n;
    Try(1);
    cout << ans;    
    return 0;
}