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

int ans;
char bc[8][8];

bool check(int r, int c) {
    // cot
    for (int i = 0; i < r; i++)
        if (bc[i][c] == 'Q')
            return false;
    
    // cheo chinh
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (bc[i][j] == 'Q')
            return false;
    
    // cheo phu
    for (int i = r, j = c; i >= 0 && j < 8; i--, j++) 
        if (bc[i][j] == 'Q')
            return false;
    
    return true;
}

void Try(int r) {
    if (r == 8) {
        ans++;
        return;
    }
    
    for (int c = 0; c < 8; c++) {
        if (bc[r][c] == '.' && check(r, c)) {
            bc[r][c] = 'Q';
            
            Try(r + 1);
            
            bc[r][c] = '.';
        }
    }
}

signed main() {
    fastIO;
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> bc[i][j];
    
    Try(0);
    cout << ans;
    return 0;
}   