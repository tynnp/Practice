#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, ans = -1, sum = 0;
        cin >> a >> b;
        
        vector<int> v(a);
        for (int i = 0, j = 0; i < a; i++) {
            cin >> v[i];
            sum += v[i];
            if (sum > b) sum -= v[j++];
            if (sum == b) ans = max(ans, i - j + 1);
        }
        
        ans = a - ans;
        if (ans > a || ans == -1) cout << -1;
        else cout << ans;
        cout << endl;
    }
    
    return 0;
}