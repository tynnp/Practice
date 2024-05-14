#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, MIN;
int xA, yA, xB, yB;
char maTran[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void Try(int x, int y) {
    if (x == xB && y == yB) {
        if (cnt < MIN) MIN = cnt;
    } else {
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && maTran[xx][yy] != '*') {
                char tmp = maTran[xx][yy];
                maTran[xx][yy] = '*';
                cnt++;
                
                Try(xx, yy);
                
                maTran[xx][yy] = tmp;
                cnt--;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            cin >> maTran[i][j];
            if (maTran[i][j] == 'B') xA = i, yA = j;
            if (maTran[i][j] == 'C') xB = i, yB = j;
        }
        
    MIN = INT_MAX;
    cnt = 0;
    Try(xA, yA);

    cout << MIN << endl;
    return 0;
}
