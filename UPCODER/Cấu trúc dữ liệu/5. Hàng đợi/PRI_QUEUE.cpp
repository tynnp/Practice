#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c;
    priority_queue<int> q;
    queue<int> ans;
    
    while (cin >> c) {
        if (c == '+') {
            cin >> n;
            if (q.size() < 15000)
                q.push(n);
        } else {
            if (!q.empty()) {
                int Max = q.top(); 
                while (!q.empty() && q.top() == Max) 
                    q.pop();
            }
        }
    }
    
    while (!q.empty()) {
        if (ans.empty() || ans.back() != q.top())
            ans.push(q.top());
        q.pop();
    }
    
    cout << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    
    return 0;
}