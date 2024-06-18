#include <bits/stdc++.h>
using namespace std;

int n, sum, MAX(INT_MIN);
char maTran[101][101];
vector<char> duongDi;

int dx[] = {1, 1};
int dy[] = {0, 1};

void Try(int x, int y) {
    if (x == n) {
        for (int i = 2; i < n; i += 2) {
            if (duongDi[i-1] == '-') sum -= duongDi[i] - '0';
            else sum += duongDi[i] - '0';
        }
        
        if (sum > MAX) MAX = sum;
        sum = maTran[1][1] - '0';
        
    } else {
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= xx) {
                duongDi.push_back(maTran[xx][yy]);
                Try(xx, yy);
                duongDi.pop_back();
            }
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> maTran[i][j];
            
    sum = maTran[1][1] - '0';
    duongDi.push_back(maTran[1][1]);
    Try(1, 1);
    
    cout << MAX;
    return 0;
}