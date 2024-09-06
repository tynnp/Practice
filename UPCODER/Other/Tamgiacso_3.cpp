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

const int MAXN = 8 + 5;
const int MOD = 1e9 + 7;

int n, sum, ans;
int a[MAXN][MAXN];

vector<int> duongDi;
vector<int> ketQua;

int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

void Try(int x, int y) {
    if (x == n) {
        if (sum > ans) {
            ans = sum;
            ketQua = duongDi;
        }
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        
        if (u >= 1 && u <= n && v >= 1 && v <= u) {
            sum += a[u][v];
            duongDi.push_back(a[u][v]);
            
            //cout << u << " " << v << endl;
            Try(u, v);
            
            sum -= a[u][v];
            duongDi.pop_back();
        }
    }
}

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    
    ans = sum = a[1][1];
    duongDi.push_back(a[1][1]);
    ketQua = duongDi;
    Try(1, 1);
    
    cout << ans << endl;
    for (int i = 0; i < ketQua.size(); i++)
        cout << ketQua[i] << ' ';
    
    return 0;
}