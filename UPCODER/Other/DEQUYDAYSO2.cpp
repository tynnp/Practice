#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 15 + 5;
const int MOD = 1e9 + 7;

int n, sum;
int a[MAXN];
vector<int> duongDi;
vector<vector<int>> ketQua;

void Try(int idx) {
    if (sum != 0 && sum & 1) 
        ketQua.push_back(duongDi);
    
    for (int i = idx + 1; i < n; i++) {
        duongDi.push_back(a[i]);
        sum += a[i];
        
        Try(i);
        
        duongDi.pop_back();
        sum -= a[i];
    }
}

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    for (int i = 0; i < n; i++) {
        duongDi.push_back(a[i]);
        sum += a[i];
        
        Try(i);
        
        duongDi.pop_back();
        sum -= a[i];
    }
    
    sort(ketQua.begin(), ketQua.end());
    
    if (ketQua.size() == 0)
        cout << -1;
    else {
        for (auto x : ketQua) {
            for (auto y : x)  
                cout << y << " ";
            cout << endl;
        }
    }
    
    return 0;
}