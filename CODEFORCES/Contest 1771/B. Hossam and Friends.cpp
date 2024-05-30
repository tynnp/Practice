#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        long long n, m, ans(0);
        cin >> n >> m;
 
        vector<int> v(n+1, n+1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            
            if (a > b) swap(a, b);
            v[a] = min(v[a], b);
        }
        
        for (int i = n-1; i >= 1; i--)
                v[i] = min(v[i], v[i+1]);
 
        for (int i = 1; i <= n; i++)
            ans += v[i] - i;
        
        cout << ans << endl;
    }
 
    return 0;
}