#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n+1, 0);
    vector<int> b(n+1, 0);
    a[1] = 0; b[1] = 1;
    a[2] = 1; b[2] = 1;
    
    for (int i = 3; i <= n; i++)
        a[i] = b[i-1],
        b[i] = b[i-1] + a[i-1];
        
    cout << a[n] << " " << b[n]; 
    return 0;
}