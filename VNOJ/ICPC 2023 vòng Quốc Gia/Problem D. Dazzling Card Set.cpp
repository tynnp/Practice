#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        unordered_set<int> s;
        vector<int> v(n);
        for (int &x : v) cin >> x;

        long long i = 0, j = 0, ans = 0;
        while (j < n) {
            while (j < n && s.find(v[j]) == s.end()) {
                s.insert(v[j]);
                j++;
                ans += j - i;
            }

            s.erase(v[i]);
            i++;
        }

        cout << ans << '\n';
    }
}