#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, du = 0;
    stack<int> s;
    cin >> n;
    
    vector<int> v(n);
    for (int &x : v) cin >> x;
    reverse(v.begin(), v.end());

    for (int x : v) {
        x = x*2 + du;
        du = 0;
        
        if (x > 9) {
            x %= 10;
            du = 1;
        }
        
        s.push(x);
    }
    
    if (du > 0) s.push(du);
    
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    
    return 0;
}