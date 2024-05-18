#include <bits/stdc++.h>
using namespace std;

struct ToaDo {
    int first, second;
    ToaDo(int a, int b): first(a), second(b) {}
};

int xA, yA, xB, yB, nangLuong, MAX(INT_MIN);
bool check[21][21] = {false};
bool timThay = false;
vector<ToaDo> buocNhay;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

void Try(int x, int y) {
    if (nangLuong == MAX) return;
    
    if (x == xB && y == yB) {
        MAX = max(nangLuong, MAX);
        timThay = true;
        
    } else {
        for (int i = 0; i < buocNhay.size()-1; i++) {
            int u = buocNhay[i+1].first;
            int v = buocNhay[i+1].second;
            
            if (x == buocNhay[i].first && y == buocNhay[i].second && !check[u+10][v+10] && nangLuong > 0) {
                nangLuong--;
                check[u+10][v+10] = true;
                
                Try(u, v);
                
                nangLuong++;
                check[u+10][v+10] = false;
                break;
            }
        }
        
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= -10 && xx <= 10 && yy >= -10 && yy <= 10 && !check[xx+10][yy+10] && nangLuong > 0) {
                nangLuong--;
                check[xx+10][yy+10] = true;
                 
                Try(xx, yy);
                
                nangLuong++;
                check[xx+10][yy+10] = false;
            }
        }
    }
}

int main() {
    cin >> xA >> yA >> xB >> yB;
    
    int t;
    cin >> t >> nangLuong;
    
    while (t--) {
        int a, b;
        cin >> a >> b;  
        buocNhay.push_back({a, b});
    }
    
    check[xA][yA] = true;
    Try(xA, yA);
    
    if (timThay) cout << "YES\n" << MAX;
    else cout << "NO";
    return 0;
}