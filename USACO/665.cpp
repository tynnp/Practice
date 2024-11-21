#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("cowsignal.in", "r", stdin)
#define out freopen("cowsignal.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 10 + 5;
const int MOD = 1e9 + 7;

int n, m, k;
char c[MAXN][MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= k; x++) {
            for (int j = 1; j <= m; j++) 
                for (int y = 1; y <= k; y++)
                    cout << c[i][j];
            cout << endl;
        }
    }
    
    return 0;
}