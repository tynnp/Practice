#include <bits/stdc++.h>
using namespace std;

struct ToaDo {
    int x, y;
};

int main() {
    int n, ans = 0;
    cin >> n;
    
    ToaDo list[n];
    for (auto &e : list)
        cin >> e.x >> e.y;
        
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            ans += list[i].y == list[j].y;
    
    cout << ans;
    return 0;
}