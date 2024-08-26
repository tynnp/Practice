#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
vector<int> v;
stack<int> s;

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] >= v[i]) 
            s.pop();
            
        if (s.empty())  
            cout << 0 << " ";
        else 
            cout << s.top() + 1 << " ";
      
        s.push(i);
    }
    
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define int long long
// #define inp freopen("file.inp", "r", stdin)
// #define out freopen("file.out", "w", stdout)
// #define TIME 1.0*clock()/CLOCKS_PER_SEC
// #define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

// const int MAXN = 2e5 + 5;
// const int MOD = 1e9 + 7;

// int n, sl = 1;
// int a[MAXN], res[MAXN], res2[MAXN];


// signed main() {
//     fastIO;
//     cin >> n;
//     cin >> a[0];
    
//     res[0] = a[0];
//     res2[0] = 1;
    
//     cout << 0 << " ";
    
//     for (int i = 1; i < n; i++) {
//         cin >> a[i];
//         int x = upper_bound(res, res + sl, a[i]) - res;
        
//         if (x == 0) {
//             cout << 0 << " ";
//             res[x] = a[i];
//             res2[x] = i + 1;
//             sl = 1;
//         } else {
          
//           if (res[x - 1] == a[i]) 
//               --x;
          
//           cout << res2[x - 1] << ' ';
//           res[x] = a[i];
//           res2[x] = i + 1;
//           sl = x + 1;
//         }
//     }
    
//     // 0 1 0 3 4 3 3 7
//     return 0;
// }