#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    stack<char> s;
    
    cin >> str;
    for (char c : str) {
        if (c != '*') s.push(c);
        else if (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
    
    return 0;
}