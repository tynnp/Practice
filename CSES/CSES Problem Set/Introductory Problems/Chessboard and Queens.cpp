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
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 8;
const int MOD = 1e9 + 7;

int ans;
char a[MAXN][MAXN];

bool check(int r, int c) {
    for (int i = 0; i < MAXN; i++)
        if (a[i][c] == 'Q')
            return false;
    
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (a[i][j] == 'Q') 
            return false;

    for (int i = r, j = c; i >= 0 && j < MAXN; i--, j++)
        if (a[i][j] == 'Q')
            return false;
    
    return true;
}

void Try(int r) {
    if (r == MAXN) {
        ans++;
        return;
    }

    for (int c = 0; c < MAXN; c++) {
        if (a[r][c] == '.' && check(r, c)) {
            a[r][c] = 'Q';

            Try(r + 1);
            
            a[r][c] = '.';
        }
    }
}

signed main() {
    fastIO;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            cin >> a[i][j];
    
    Try(0);
    cout << ans;
    return 0;
}