#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, ans;
    cin >> n >> m >> k;
    
    if (n & 1) ans = max(m, k);
    else ans = min(m, k);
    
    while (n--)
        cout << ans << " ";
    return 0;
}