#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, t, sum(0), ans(0);
    cin >> n >> t;
    
    vector<int> v(n);
    for (int &x : v) cin >> x;
    //sort(v.begin(), v.end());
    
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && sum + v[j] <= t) 
            sum += v[j++];
        ans = max(ans, j - i);
        sum -= v[i];
        i++;
    }
    
    cout << ans;
    return 0;
}