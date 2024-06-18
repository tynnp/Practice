#include <bits/stdc++.h>
using namespace std;

int ans;
string inp, str;
vector<string> hauTo;

int priority(char);
int tinh(int, int, char);
void themKhoangTrang();
void trungToSangHauTo();
void tinhGiaTri();

int main() {
    cin >> inp;
    themKhoangTrang();
    trungToSangHauTo();
    tinhGiaTri();
    cout << ans;
    return 0;
}

void themKhoangTrang() {
    str = "";
    for (int i = 0; i < inp.size(); i++) {
        if (!isdigit(inp[i])) str += ' ';
        str += inp[i];
        if (isdigit(inp[i+1]) && !isdigit(inp[i])) str += ' ';
    }
}

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void trungToSangHauTo() {
    string tmp;
    stack<string> s;
    stringstream ss(str);
    
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

int tinh(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    return pow(a, b);
}

void tinhGiaTri() {
    stack<int> s;
    
    for (string x : hauTo) {
        if (isdigit(x[0]))
            s.push(stoi(x));
            
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            char c = x[0];
            s.push(tinh(a, b, c));
        }
    }
    
    ans = s.top();
}