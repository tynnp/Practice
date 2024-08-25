// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define int long long
// #define inp freopen("file.inp", "r", stdin)
// #define out freopen("file.out", "w", stdout)
// #define TIME 1.0*clock()/CLOCKS_PER_SEC
// #define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

// const int MAXN = 1e6 + 5;
// const int MOD = 1e9 + 7;

// int n, s;
// vector<pair<int, int>> v;

// void solve() {
//     cin >> n >> s;
//     for (int i = 1; i <= n; i++) {
//         int tmp;
//         cin >> tmp;
//         v.push_back({tmp, i});
//     }
    
//     sort(v.begin(), v.end());
//     int i = 0, j = n - 1;
    
//     while (i < j) {
//         int x = v[i].first + v[j].first;
//         if (x == s) {
//             cout << v[i].second << " " << v[j].second;
//             return;
//         }
        
//         if (x > s) j--;
//         else i++;
//     }
    
//     cout << "IMPOSSIBLE";
// }

// signed main() {
//     fastIO;
//     int t;
//     //cin >> t;
//     t = 1;
    
//     while (t--)
//         solve();
//     return 0;
// }

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
vector<pair<int, int>> v;

int binary_search(int l, int r, int e) {
    if (l > r)
        return -1;

    int mid = (l + r) / 2;

    if (v[mid].first == e)
        return v[mid].second;

    if (v[mid].first < e) 
        return binary_search(mid + 1, r, e);
    else 
        return binary_search(l, mid - 1, e);
} 

void solve() {
    cin >> n >> x;
    v.push_back({0, 0});
    
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }

    sort(v.begin(), v.end());
    // for (int i = 1; i <= n; i++)
    //     cout << v[i].first << " " << v[i].second << endl;
    
    for (int i = 1; i <= n; i++) { 
        pair<int, int> p = v[i];
        // cout << p.first <<" " << p.second << endl;
        
        int k = binary_search(i+1, n, x - p.first);
        
        if (k != -1) {
            cout << p.second << " " << k;
            return;
        }
    }
    
    cout << "IMPOSSIBLE";
}

signed main() {
    fastIO;
    solve();
    return 0;
}