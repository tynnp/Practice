#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, x, y;
int vt[101][101];
bool visited[101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int y, int x, int n, int m) {
    return y >= 1 && y <= n && x >= 1 && x <= m;
}

int BFS(int u, int v) {
    queue<pair<int, int>> q;
    q.push({u, v});
    visited[u][v] = true;
    int cnt = 0;
    
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int yy = curY + dy[i];
            int xx = curX + dx[i];

            if (isValid(yy, xx, n, m) && !visited[yy][xx] && vt[yy][xx] == 0) {
                q.push({yy, xx});
                visited[yy][xx] = true;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m >> y >> x;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> vt[i][j];

    memset(visited, false, sizeof(visited));
    int res = BFS(y, x);
    cout << res;
    return 0;
}