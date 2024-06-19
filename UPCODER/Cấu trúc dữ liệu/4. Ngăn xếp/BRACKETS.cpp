#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n;
    stack<int> s;
    vector<char> ans;
    cin >> q;
    
    while (q--) {
        cin >> n;
        s.push(n);
    }
    
    while (!s.empty()) {
        int k = s.top();
        
        if (k == 0) ans.insert(ans.begin(), {'(', ')'});
        else {
            ans.insert(ans.begin(), '(');
            ans.insert(ans.begin() + k, ')');
        }
        
        s.pop();
    }
    
    for (char c : ans) cout << c;
    return 0;
}