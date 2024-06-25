#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, left, right;
        cin >> n >> left >> right;
    
        vector<int> v(n);
        for (int &x : v) cin >> x;
        sort(v.begin(), v.end());
    
        long long i = 0, ans = 0;
        while (i < n) {
            int x = lower_bound(v.begin() + i + 1, v.end(), left - v[i]) - v.begin();
            int y = upper_bound(v.begin() + i + 1, v.end(), right - v[i]) - v.begin();
            ans += y - x;
            i++;
        }
    
        cout << ans << endl;
    }
    
    return 0;
}
