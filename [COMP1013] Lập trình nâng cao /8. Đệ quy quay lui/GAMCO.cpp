#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, s, t;
char vt[101][101];
int cnt[101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int u, int v) {
    return u >= 1 && u <= n && v >= 1 && v <= m && vt[u][v] != '*';
}

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vt[x][y] = '*';
    cnt[x][y] = 0;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();    

        for (int i = 0; i < 4; i++) {
            int u = xx + dx[i];
            int v = yy + dy[i];
            cnt[u][v] = cnt[xx][yy] + 1;

            if (u == s && v == t) return;
            if (isValid(u, v)) { 
                q.push({u, v});
                vt[u][v] = '*';
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> vt[i][j];
            if (vt[i][j] == 'C') s = i, t = j;
        }
    }

    BFS(1, 1);
    cout << cnt[s][t];
    return 0;
}