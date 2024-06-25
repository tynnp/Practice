#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    for (int &x : b) 
        cout << upper_bound(a.begin(), a.end(), x) - a.begin() << " ";
    
    return 0;
}