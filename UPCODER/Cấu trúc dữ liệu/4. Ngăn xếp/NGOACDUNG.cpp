#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    stack<char> s;
    
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[' || s.empty()) s.push(c);
        else if (
            s.top() == '(' && c == ')' ||
            s.top() == '[' && c == ']' ||
            s.top() == '{' && c == '}'
        ) s.pop();
    }
        
    return s.empty();
}

int main() {
    string str;
    getline(cin, str);
    cout << (check(str) ? "yes" : "no");
    return 0;
}