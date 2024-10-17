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

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

int n, maxLen;
pair<int, int> a[MAXN];
int pos[MAXN];

void solve() {
    // tăng dần theo chiều dài
    sort(a + 1, a + n + 1);
    
    maxLen = 1;
    pos[0] = a[n].second;

    // vì đăng tăng dần theo l nên duyệt ngược xử lí w
    for (int i = n-1; i >= 1; i--) {

        // tìm vị trí có thể chèn trọng lượng của đoạn gỗ hiện tại 
        int k = lower_bound(pos, pos + maxLen, a[i].second) - pos;

        // nếu không có thì mở rộng
        if (k == maxLen) {
            maxLen++;
            pos[k] = a[i].second;

        // nếu có thì thay thế
        } else  
            pos[k] = min(pos[k], a[i].second);
    }

    cout << maxLen << endl;
}

signed main() {
    fastIO;
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        solve();
    }
    
    return 0;
}