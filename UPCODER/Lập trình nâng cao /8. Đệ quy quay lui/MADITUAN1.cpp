#include <bits/stdc++.h>
using namespace std;

int n, cnt, res(0);
int banCo[100][100];

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void Try(int x, int y) {
    if (cnt == n*n) res++;
    else {
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && banCo[xx][yy] == 0) {
                cnt += 1;
                banCo[xx][yy] = 1;
                
                Try(xx, yy);
                
                cnt -= 1;
                banCo[xx][yy] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            banCo[i][j] = 0;
            
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cnt = 1;
            banCo[i][j] = 1;
            Try(i, j);
            banCo[i][j] = 0;
        }
        
    cout << res;
    return 0;
}