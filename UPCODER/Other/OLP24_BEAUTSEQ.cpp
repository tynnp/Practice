#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int arr[MAXN];
int sum[MAXN];

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] += sum[i-1] + arr[i];
    }
    
    int i = 1, j = 1;
    while (j <= n) {
        if (arr[j] % 3 == 0) {
            ans = max(ans, sum[j-1] - sum[i-1]);
            i = j + 1;
        }
        j += 1;
    }
    
    cout << ans << endl;
    //cout << TIME;
    return 0;
} 