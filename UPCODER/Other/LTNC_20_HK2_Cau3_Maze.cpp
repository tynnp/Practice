#include <bits/stdc++.h>
using namespace std;

int n, m, MIN;
int xA, yA, xB, yB;
char maTran[100][100];
vector<pair<int, int>> ketQua, duongDi;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void Try(int x, int y) {
    if (x == xB && y == yB) {
        if (duongDi.size() < MIN) {
            MIN = duongDi.size();
            ketQua = duongDi;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && maTran[xx][yy] != '*') {
                char tmp = maTran[xx][yy];
                maTran[xx][yy] = '*';
                duongDi.push_back({xx, yy});
                
                Try(xx, yy);
                
                maTran[xx][yy] = tmp;
                duongDi.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            cin >> maTran[i][j];
            if (maTran[i][j] == 'A')
                xA = i, yA = j;
            if (maTran[i][j] == 'B')
                xB = i, yB = j;
        }
        
    MIN = n*m;
    duongDi.push_back({xA, yA});
    Try(xA, yA);

    cout << MIN << endl;
    for (auto p : ketQua)
        cout << "(" << p.first << "," << p.second << ") ";
    
    return 0;
}
