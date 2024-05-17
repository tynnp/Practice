#include <bits/stdc++.h>
using namespace std;

struct ToaDo {
    int first, second;
    ToaDo(int a, int b): first(a), second(b) {}
};

int n, m, xA, yA, xB, yB;
int banCo[1001][1001];
queue<ToaDo> q;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    cin >> n >> m >> xA >> yA >> xB >> yB;
    q.push({xA, yA});
    
    while (!q.empty()) {
        ToaDo cur = q.front();
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int xx = cur.first + dx[i];
            int yy = cur.second + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && banCo[xx][yy] == 0) {
                banCo[xx][yy] = banCo[cur.first][cur.second] + 1;
                q.push({xx, yy});
            }
        }
    }
    
    cout << (banCo[xB][yB] == 0 ? -1 : banCo[xB][yB]);
    return 0;
}