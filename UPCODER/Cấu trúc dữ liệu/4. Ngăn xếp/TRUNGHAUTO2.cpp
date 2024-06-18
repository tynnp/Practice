#include <bits/stdc++.h>
using namespace std;

string inp;
vector<string> hauTo;
int priority(char);
void trungToSangHauTo();

int main() {
    getline(cin, inp);
    trungToSangHauTo();
    for (string s : hauTo) 
        cout << s << " ";
    return 0;
}

int priority(char c) {
    if (c == '^') return 5;
    if (c == '*') return 4;
    if (c == '/') return 3;
    if (c == '+') return 2;
    if (c == '-') return 1;
    return 0;
}

void trungToSangHauTo() {
    string tmp;
    stack<string> s;
    stringstream ss(inp);
    
    while (ss >> tmp) {
        if (isdigit(tmp[0])) hauTo.push_back(tmp);
        else if (tmp[0] == '(') s.push(tmp);
        
        else if (tmp[0] == ')') {
            while (!s.empty() && s.top() != "(") {
                hauTo.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        
        else {
            while (!s.empty() && priority(s.top()[0]) > priority(tmp[0])) {
                hauTo.push_back(s.top());
                s.pop();
            }
            s.push(tmp);
        }
    }
    
    while (!s.empty()) {
        hauTo.push_back(s.top());
        s.pop();
    }
}