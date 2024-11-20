#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("buckets.in", "r", stdin)
#define out freopen("buckets.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    const int n = 10;
    char c[n][n];

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) 
            c[i][j] = row[j];
    }

    int barnX, barnY, lakeX, lakeY, rockX, rockY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == 'B') 
                barnX = i, barnY = j;

            if (c[i][j] == 'L')
                lakeX = i, lakeY = j;

            if (c[i][j] == 'R')
                rockX = i, rockY = j;
        }
    }

    int ans = abs(lakeX - barnX) + abs(barnY - lakeY) - 1;

    if (barnY == lakeY && rockY == barnY && ((lakeX < rockX && rockX < barnX) || (barnX < rockX && rockX < lakeX)))
        ans += 2;

    if (barnX == lakeX && rockX == barnX && ((lakeY < rockY && rockY < barnY) || (barnY < rockY && rockY < lakeY)))
        ans += 2;
    
    cout << ans;
    return 0;
}