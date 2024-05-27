#include <bits/stdc++.h>
using namespace std;

struct doan {
    int type, len;
    doan(int a, int b): type(a), len(b) {}
};

    int main() {
    int n, ans(0);
    cin >> n;

    vector<int> v(n);
    for (int &x : v) cin >> x;

    vector<doan> res;
    int curType = v[0], curLen = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] == curType) curLen++;
        else {
            res.push_back({curType, curLen});
            curType = v[i], curLen = 1;
        }
    }

    res.push_back({curType, curLen});
    for (int i = 0; i < res.size()-1; i++) 
        if (res[i].type != res[i+1].type) {
            int tmp = min(res[i].len, res[i+1].len) * 2;
            ans = max(ans, tmp);
        }
    
    cout << ans;
    return 0;
}
