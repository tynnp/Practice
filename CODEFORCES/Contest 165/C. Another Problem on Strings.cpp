#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long k, ans(0);
    string s;
    cin >> k >> s;
    
    map<int, int> m;
    vector<int> sum(s.size()+1, 0);
    m[0] = 1;
 
    for (int i = 0; i < s.size(); i++) {
        sum[i+1] = sum[i] + (s[i]-'0');
        
        if (m.find(sum[i+1] - k) != m.end())
            ans += m[sum[i+1] - k];
        
        m[sum[i+1]]++;
    }
 
    cout << ans;
    return 0;
}