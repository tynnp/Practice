#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("perimeter.in", "r", stdin)
#define out freopen("perimeter.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1000 + 5;
const int MOD = 1e9 + 7;

int n, peri, area;
int periMin, areaMax;
char c[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = true;
    area++;

    for (int i = 0; i < 4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];

        if (u < 1 || u > n || v < 1 || v > n || c[u][v] == '.') {
            peri++;
            continue;
        }

        if (!visited[u][v] && c[u][v] == '#')
            dfs(u, v);
    }
}

signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++)    
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    
    areaMax = 0;
    periMin = LLONG_MAX;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == '#' && !visited[i][j]) {
                area = peri = 0;
                dfs(i, j);

                if (area > areaMax) {
                    areaMax = area;
                    periMin = peri;
                } else if (area == areaMax) {
                    periMin = min(periMin, peri);
                }
            }
        }
    }

    cout << areaMax << ' ' << periMin;
    return 0;
}