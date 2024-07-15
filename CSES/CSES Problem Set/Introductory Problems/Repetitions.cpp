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
 
int n, check[MAXN];
int tmp, ans;
 
// void solve() {
//     int tmp;
//     cin >> n;
 
//     for (int i = 0; i < n; i++) {
//         cin >> tmp;
//         check[tmp] = 1;
//     }
 
//     for (int i = 1; i <= n; i++)
//         if (!check[i]) {
//             cout << i;
//             return;
//         }
// }
 
void solve() {
    cin >> n;
    ans = n*(n+1) / 2;
 
    while (n > 1) {
        cin >> tmp;
        ans -= tmp;
        n--;
    }
 
    cout << ans;
}
 
signed main() {
    fastIO;
    solve();
    return 0;
}