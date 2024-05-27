#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans(0);
    string s;
    cin >> n >> k >> s;
    
    vector<int> v(n), cnt(2, 0);
    for (int &x : v) cin >> x;
    
    for (int i = 0, j = 0; j < n; j++) {
        cnt[s[j] - 'a']++;
        
        while (min(cnt[0], cnt[1]) > k) {
            cnt[s[i] - 'a']--;
            i++;
        }
        
        ans = max(ans, j - i + 1);
    }
    
    cout << ans;
    return 0;
}