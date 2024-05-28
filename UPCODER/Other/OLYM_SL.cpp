#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    int ans(0), cnt(0), i(0), j(0);
    while (j < n) {
        cnt += v[j] < 0;
        while (cnt > 2 && i < j) 
            cnt -= v[i] < 0, i++;
        ans = max(ans, j - i + 1);
        j++;
    }
    
    cout << ans;
    return 0;
}