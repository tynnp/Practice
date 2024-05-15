#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
int maTran[100][100];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool Try(int x, int y) {
    if (x == c && y == d) return true;
    else {
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && maTran[xx][yy] == 0) {
                maTran[xx][yy] = 1;
                if (Try(xx, yy)) return true;
                maTran[xx][yy] = 0;
            }
        }
    }
    
    return false;
}

int main() {
    ifstream fin("LINE.inp");
    ofstream fout("LINE.out");
    
    fin >> n >> a >> b >> c >> d;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> maTran[i][j];
    
    fout << (Try(a, b) ? "YES" : "NO");
    
    fin.close();
    fout.close();
    return 0;
}