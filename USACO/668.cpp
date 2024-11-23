#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("moocast.in", "r", stdin)
#define out freopen("moocast.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 205 + 5;
const int MOD = 1e9 + 7;

int n, ans;
int x[MAXN], y[MAXN], p[MAXN];
bool c[MAXN][MAXN];
bool visited[MAXN];

int dfs(int u) {
    if (visited[u])
        return 0;

    visited[u] = true;
    int res = 1;

    for (int i = 1; i <= n; i++) 
        if (c[u][i]) 
            res += dfs(i);

    return res;
}
    
signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> x[i] >> y[i] >> p[i];

    // Ma trận kề biểu diễn đồ thị có hướng
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int d = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
            c[i][j] = d <= p[i] * p[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        ans = max(ans, dfs(i));
    }
        
    cout << ans;
    return 0;
}