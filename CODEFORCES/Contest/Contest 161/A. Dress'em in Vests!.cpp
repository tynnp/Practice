#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;

struct Vest {
    int x, y;
    Vest() {};
    Vest(int a, int b): x(a), y(b) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    int n, m, x, y, k;
    vector<Vest> a(MAXN);
    vector<int> b(MAXN);
    vector<Vest> res;
    cin >> n >> m >> x >> y;
    
    for (int i = 1; i <= n; i++) {
        cin >> k;
        a[i] = {k - x, k + y};
    }
    
    for (int i = 1; i <= m; i++)
        cin >> b[i];
        
    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (b[j] >= a[i].x && b[j] <= a[i].y)   
            res.push_back({i++, j++});
        else if (a[i].y < b[j]) i++;
        else j++;
    }
    
    cout << res.size() << '\n';
    for (auto &r : res)
        cout << r.x << " " << r.y << '\n';
    
    return 0;
}