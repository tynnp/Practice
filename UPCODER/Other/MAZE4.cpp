// đúng 28/30

#include <bits/stdc++.h>
using namespace std;

int n, m, sX, sY;
string str, cur;
char maTran[6][6];
bool check[6][6], dp[257];

int dx[] = {-1, 0, 0, 1, -1, 1, 1, -1};
int dy[] = {0, -1, 1, 0, -1, -1, 1, 1};

bool Try(int &x, int &y) {
    if (cur == str) return true;
    else {
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && xx >= 1 && xx <= m && !check[xx][yy]) {
                check[xx][yy] = true;
                cur.push_back(maTran[xx][yy]);
                
                if (str.find(cur) != string::npos) {
                    if (Try(xx, yy)) return true;
                }
                
                check[xx][yy] = false;
                cur.pop_back();
            } 
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            cin >> maTran[i][j];
            dp[maTran[i][j]] = true;
            check[i][j] = false;
        }
    
    bool stop = false;
    cin.ignore();
    getline(cin, str);
    
    for (const char &c : str) 
        if (dp[c] == false) {
            stop = true;
            break;
        }
    
    if (stop) cout << "NO";
    else {
        for (int i = 1; i <= n; i++) {
            if (stop) break;
            
            for (int j = 1; j <= m; j++) {
               if (maTran[i][j] == str[0]) {
                   check[i][j] = true;
                   cur.push_back(maTran[i][j]);
                   
                   if (Try(i, j)) {
                       cout << "YES";
                       stop = true;
                       break;
                   }
                   
                   check[i][j] = false;
                   cur.pop_back();
               }
           }
        }
    }
    
    if (!stop) cout << "NO";
    return 0;
}