#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cur;
    vector<int> v;
    
    while (cin >> n)
        v.push_back(n);
    
    cur = v[0]; 
    cout << v[0] << " ";
    
    for (int x : v)   
        if (x <= cur) continue;
        else {
            cout << x << " ";
            cur = x;
        }
        
    return 0;
}