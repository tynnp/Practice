#include <bits/stdc++.h>
using namespace std;

ifstream fin("EM_HUA_HOC_TAP_TOT.INP");
ofstream fout("VA_SE_KHONG_GIAN_LAN.OUT");

struct ToaDo {
    int first, second;
    ToaDo(int a, int b): first(a), second(b) {}
};

int n, m, sum(0), MAX(INT_MIN);
int giaTri[1001][1001];
vector<ToaDo> ketQua, duongDi;

int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

void Try(int x, int y) {
    if (y == m) {
        if (sum > MAX) {
            MAX = sum;
            ketQua = duongDi;
        }
    } else {
        for (int i = 0; i < 3; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                duongDi.push_back({xx, yy});
                sum += giaTri[xx][yy];
                
                Try(xx, yy);
                
                duongDi.pop_back();
                sum -= giaTri[xx][yy];
            }
        }
    }
}

int main() {
    fin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            fin >> giaTri[i][j];
            
    for (int i = 1; i <= n; i++) {
        sum = giaTri[i][1];
        duongDi.push_back({i, 1});
        
        Try(i, 1);
        
        sum = 0;
        duongDi.pop_back();
    }
    
    fout << MAX << endl;
    for (auto x : ketQua) 
        fout << "(" << x.first << "," << x.second << ") ";
        
    fin.close();
    fout.close();
    return 0;
}