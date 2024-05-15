#include <bits/stdc++.h>
using namespace std;

int n, m, dem(0);
int maTran[100][100];
bool nam[4] = {false};

int dx[] = {0, 1};
int dy[] = {1, 0};

void Try(int x, int y) {
    if (x == n && y == m) {
        for (int i = 0; i < 3; i++) nam[i] = nam[i] > 0;
        if (nam[1] + nam[2] + nam[3] >= 2) dem += 1;
            
    } else {
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && y >= 1 && y <= m && maTran[xx][yy] != -1) {
                for (int i = 1; i <= 3; i++)
                    nam[i] += maTran[xx][yy] == i;
                int tmp = maTran[xx][yy];
                maTran[xx][yy] = -1;
                
                Try(xx, yy);
                
                maTran[xx][yy] = tmp;
                for (int i = 1; i <= 3; i++)
                    nam[i] -= maTran[xx][yy] == i;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> maTran[i][j];
    
    Try(1, 1);
    cout << (dem == 0 ? -1 : dem);
    return 0;
}