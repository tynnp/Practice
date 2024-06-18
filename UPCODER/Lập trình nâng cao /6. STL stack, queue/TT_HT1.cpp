#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char c;
    stack<char> s;
    
    while (cin >> c) {
        if (isalnum(c)) cout << c;
        else if (c == '(') s.push(c);
        
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        
        else {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    
    return 0;
}