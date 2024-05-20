#include <bits/stdc++.h>
using namespace std;

int n;
int maTran[1001][1001];
string res("");

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
char dc[] = {'X', 'P', 'T', 'L'};

void Try(int x, int y) {
    if (x == n && y == n) {
        cout << res << '\n';
    } else {
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && maTran[xx][yy] == 1) {
                res.push_back(dc[i]);
                maTran[xx][yy] = 0;
                
                Try(xx, yy);
                
                res.pop_back();
                maTran[xx][yy] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> maTran[i][j];
    
    if (maTran[1][1] == 0 || maTran[n][n] == 0) cout << -1;
    else {
        maTran[1][1] = 0;
        
        for (int k = 0; k < 2; k++) {
            int xx = 1 + dx[k];
            int yy = 1 + dy[k];
            
            maTran[xx][yy] = 0;
            res.push_back(dc[k]);
            
            Try(xx, yy);
            
            res.pop_back();
            maTran[xx][yy] = 1;
        }
    }
    
    return 0;
}