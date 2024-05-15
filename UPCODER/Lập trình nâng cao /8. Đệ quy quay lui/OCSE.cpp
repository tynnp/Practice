#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, ketQua;
int maTran[101][101];
int du[] = {-1, 1, 0, 0};
int dv[] = {0, 0, -1, 1};

void Try(int u, int v) {
    for (int i = 0; i < 4; i++) {
        int uu = u + du[i];
        int vv = v + dv[i];
        if (uu >= 1 && uu <= n && vv >= 1 && vv <= m && maTran[uu][vv] == 0) {
            maTran[uu][vv] = 1;
            ketQua += 1;
            Try(uu, vv);
        }
    }
}

int main() {
    cin >> n >> m >> y >> x;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> maTran[i][j];
    
    maTran[y][x] = 1;
    ketQua = 1;
    Try(y, x);
    
    cout << ketQua;
    return 0;
}