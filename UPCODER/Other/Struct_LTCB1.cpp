#include <iostream>
using namespace std;

struct ToaDo {
    int x, y;
};

int n, ans;
ToaDo p[101];
bool check[101];

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> p[i].x;
        
    for (int i = 1; i <= n; i++)
        cin >> p[i].y;
        
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].x == p[j].x && !check[p[i].x]) {
                ans++;
                check[p[i].x] = true;
            }
        }
    }
    
    cout << ans;
}