#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int res(INT_MAX),i = 0, j = n-1;

    while (i < n) {
        res = min(res, abs(a[j]+b[i]));
        
        while (j > 0 && abs(a[j-1]+b[i]) <= abs(a[j]+b[i])) {
            res = min(res, abs(a[j-1]+b[i]));
            j--;
        }
        
        i++;
    }
    
    cout << res;
    return 0;
}