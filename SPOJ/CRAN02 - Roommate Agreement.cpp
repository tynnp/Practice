#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, ans(0), prefixSum(0);
        unordered_map<long long, int> m;
        cin >> n;
        
        vector<int> v(n);
        for (int &x : v) cin >> x;
        
        for (int x : v) {
            prefixSum += x;
            if (prefixSum == 0) ans++;
            
            if (m.find(prefixSum) != m.end()) {
                ans += m[prefixSum];
                m[prefixSum]++;
            } else m[prefixSum] = 1;
        }
        
        cout << ans << endl;
    }
} 