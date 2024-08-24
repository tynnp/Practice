#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
 
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
 
int n;
vector<int> v(MAXN);
 
int Try(int idx, int sumA, int sumB) {
    if (idx == n)
        return abs(sumB - sumA);
    
    int a = Try(idx + 1, sumA + v[idx], sumB);
    int b = Try(idx + 1, sumA, sumB + v[idx]);
    return min(a, b);
}
 
signed main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    int res = Try(0, 0, 0);
    cout << res;
    return 0;
}