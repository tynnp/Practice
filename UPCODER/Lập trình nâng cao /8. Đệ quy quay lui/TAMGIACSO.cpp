#include <bits/stdc++.h>
using namespace std;

int n, res;
int tamGiac[100][100];
int tong[100][100];
vector<int> ketQua, duongDi;

int dx[] = {1, 1};
int dy[] = {0, 1};

void Try(int x, int y) {
    if (x == n-1) {
        if (res < tong[x][y]) {
            res = tong[x][y];
            ketQua = duongDi;
        }
    } else {
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= 0 && xx < n && yy >= 0 && yy <= xx) {
                tong[xx][yy] = tong[x][y] + tamGiac[xx][yy];
                duongDi.push_back(tamGiac[xx][yy]);
                
                Try(xx, yy);
                
                tong[xx][yy] -= tamGiac[xx][yy];
                duongDi.pop_back();
            }
        }  
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            cin >> tamGiac[i][j];
            tong[i][j] = 0;
        }
    
    res = INT_MIN;
    tong[0][0] = tamGiac[0][0];
    duongDi.push_back(tamGiac[0][0]);
    Try(0, 0);
    
    for (int x : ketQua) cout << x << " ";
    cout << endl << res;
    return 0;
}