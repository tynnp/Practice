#include <bits/stdc++.h>
using namespace std;

int n;
int maTran[100][100];
string tmp(""), MAX("");

int dx[] = {0, 1};
int dy[] = {1, 0};

int chuyenDoi(string num) {
    int res = 0;
    int len = num.size();
    for (int i = 0; i < len; i++)
        if (num[i] == '1') 
            res += pow(2, len-1-i);
    return res;
}

void Try(int x, int y) {
    if (x == n && y == n) {
        if (tmp > MAX) MAX = tmp;
    } else {
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= 1 && x <= n && yy >= 1 && yy <= n) {
                tmp += maTran[xx][yy] + '0';
                Try(xx, yy);
                tmp.pop_back();
            }
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            cin >> maTran[i][j];
    
    tmp += maTran[1][1] + '0';
    Try(1, 1);
    cout << chuyenDoi(MAX);
    return 0;
}