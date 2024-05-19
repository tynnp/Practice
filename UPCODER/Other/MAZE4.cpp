#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, str, cur("");
char maTran[1001][1001];
bool check[1001][1001];
int dpA[1001], dpB[1001];

int dx[] = {0, 1, -1, 0, 1, 1, -1, -1};
int dy[] = {1, 0, 0, -1, 1, -1, 1, -1};

bool Try(int x, int y) {
    if (cur == str) return true;
    else if (cur.size() >= str.size()) return false;
    else {
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !check[xx][yy]) {
                check[xx][yy] = true;
                cur += maTran[xx][yy];
                
                if (str.find(cur) == 0) {
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
    cin.ignore();
    for (int &x : dpA) x = 0;   
    for (int &x : dpB) x = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maTran[i][j];
            dpA[maTran[i][j]]++;
            check[i][j] = false;
        } 
    }
    
    bool stop = false;
    cin.ignore();
    getline(cin, str);
    reverse(str.begin(), str.end());
    
    for (const auto &c : str) dpB[c]++;
    for (auto c : str) 
        if (dpA[c] < dpB[c]) {
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
                   cur += maTran[i][j];
                  
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