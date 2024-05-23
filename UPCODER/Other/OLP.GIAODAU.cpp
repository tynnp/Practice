#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res(0);
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    while (j < n) {
        if (b[j] > a[i]) res++, i++;
        j++;
    }
        
    cout << res;
}