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
 
int n;
bool check;
queue<int> q;
 
signed main() {
    fastIO;
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);
        
    while (!q.empty()) {
        if (check) 
            cout << q.front() << " ";
        else 
            q.push(q.front());
            
        q.pop();
        check = !check;
    }
    
    return 0;
}