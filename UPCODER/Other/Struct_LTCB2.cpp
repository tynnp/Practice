#include <iostream>
#include <algorithm>
using namespace std;

struct ToaDo {
    int x, y;
};

const int MAXN = 1001;
int n, cntX, cntY;
ToaDo p[MAXN];
bool check[MAXN];

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> p[i].x;
    
    for (int i = 1; i <= n; i++)
        cin >> p[i].y;
        
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].x == p[j].x && !check[p[i].x]) {
                cntX++;
                check[p[i].x] = true;
            }
        }
    }
    
    
    fill(check, check + MAXN, false);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].y == p[j].y && !check[p[i].y]) {
                cntY++;
                check[p[i].y] = true;
            }
        }
    }
    
    cout << cntX + cntY;
    return 0;
}