#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> v(n);
    for (string &x : v) cin >> x;
    
    sort(v.begin(), v.end(), [] (string a, string b) {
        return a + b > b + a;
    });
    
    for (string x : v) cout << x;
    return 0;
}