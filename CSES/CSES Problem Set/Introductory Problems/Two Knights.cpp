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

signed main() {
    fastIO;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int soCachDat = i*i * (i*i - 1) / 2;
        int soTruongHopAnNhau = (i - 1) * (i - 2) * 4;
        cout << soCachDat - soTruongHopAnNhau << endl;
    }
    
    return 0;
}