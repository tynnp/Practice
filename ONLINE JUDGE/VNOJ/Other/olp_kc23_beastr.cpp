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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, q;
string s;
int cnt[26][MAXN];

signed main() {
    fastIO;
    cin >> n >> q >> s;

    for (int i = 0; i < n; i++) 
        cnt[s[i] - 'a'][i + 1]++;

    for (int c = 0; c < 26; c++)
        for (int i = 1; i <= n; i++)
            cnt[c][i] += cnt[c][i-1];

    while (q--) {
        int l, r;
        cin >> l >> r;

        l++, r++;
        int num = 0;

        for (int c = 0; c < 26; c++) 
            if ((cnt[c][r] - cnt[c][l-1]) % 2 == 1)
                num++;

        cout << num / 2 << endl;
    }
    return 0;
}