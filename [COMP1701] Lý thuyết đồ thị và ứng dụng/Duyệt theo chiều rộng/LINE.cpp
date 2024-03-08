#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

int n, sy, sx, dy, dx;
int vt[10][10];
bool visited[10][10];

int tdx[] = {0, 0, -1, 1};
int tdy[] = {-1, 1, 0, 0};

bool check(int y, int x, int n) {
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

bool BFS(int u, int v) {
    queue<pair<int, int>> q;
    q.push({u, v});
    visited[u][v] = true;

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        if (curY == dy && curX == dx)
            return true;

        for (int i = 0; i < 4; i++) {
            int yy = curY + tdy[i];
            int xx = curX + tdx[i];

            if (check(yy, xx, n) && !visited[yy][xx] && vt[yy][xx] == 0) {
                q.push({yy, xx});
                visited[yy][xx] = true;
            }
        }
    }
    
    return false;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("LINE.inp");
    fout.open("LINE.out");

    fin >> n >> sy >> sx >> dy >> dx;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> vt[i][j];

    memset(visited, false, sizeof(visited));
    fout << (BFS(sy, sx) ? "YES" : "NO");

    fin.close();
    fout.close();
    return 0;
}
