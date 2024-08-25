#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
 
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
 
int n, x;
vector<pair<int, int>> vp;

int search(int l, int r, int k) {
    if (l > r)
        return -1;
    
    int mid = (l + r)/2;
    // cout << vp[mid].first << " " << vp[mid].second << endl;
    
    if (vp[mid].first == k)
        return vp[mid].second;
    
    if (vp[mid].first < k) 
        return search(mid + 1, r, k);
    else 
        return search(l, mid - 1, k);
}
 
void solve() {
    cin >> n >> x;
    vector<int> v(n);
    for (int &e : v) cin >> e;
    
    for (int i = 0; i < n; i++) 
        vp.push_back({v[i], i+1});
        
    sort(vp.begin(), vp.end(), [] (auto a, auto b) {
        return a.first < b.first;
    });
    
    // for (auto e : vp) 
    //     cout << e.first << " " << e.second << endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = v[i] + v[j];
            int pos = search(0, n-1, x - k);
            
            //cout << i << " " << j << " " << pos << endl;
            if (pos != -1 && j+1 != pos && i+1 != pos) {
                cout << i+1 << " " << j+1 << " " << pos;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE";
}
 
signed main() {
    int t = 1;
    while (t--)
        solve();
    return 0;
}