#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n, x;
    stack<int> s, ans;
    cin >> q;
    
    while (q--) {
        cin >> n;
        
        if (n == 1) {
            cin >> x;
            s.push(x);
            if (ans.empty()) ans.push(x);
            else ans.push(max(ans.top(), x));
        }
        
        else if (n == 2) {
            s.pop();
            ans.pop();
        }
        
        else if (n == 3) 
            cout << ans.top() << '\n';
    }
    return 0;
}