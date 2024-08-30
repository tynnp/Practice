#include <bits/stdc++.h>
using namespace std;

int ans;
string inp, str;
vector<string> hauTo;

int doUuTien(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int tinhToan(int a, int b, char phepToan) {
    if (phepToan == '+') return a + b;
    if (phepToan == '-') return a - b;
    if (phepToan == '*') return a * b;
    if (phepToan == '/') return a / b;
    if (phepToan == '^') return pow(a, b);
    return 0;
}

void trungToSangHauTo() {
    stack<char> phepToan;
    string so = "";

    for (int i = 0; i < inp.length(); i++) {
        if (isdigit(inp[i])) {
            so += inp[i];
        } else {
            if (!so.empty()) {
                hauTo.push_back(so);
                so = "";
            }
            if (inp[i] == '(') {
                phepToan.push('(');
            } else if (inp[i] == ')') {
                while (!phepToan.empty() && phepToan.top() != '(') {
                    hauTo.push_back(string(1, phepToan.top()));
                    phepToan.pop();
                }
                phepToan.pop(); // pop '('
            } else {
                while (!phepToan.empty() && doUuTien(phepToan.top()) >= doUuTien(inp[i])) {
                    if (inp[i] == '^' && phepToan.top() == '^') break; // ưu tiên kết hợp phải cho ^
                    hauTo.push_back(string(1, phepToan.top()));
                    phepToan.pop();
                }
                phepToan.push(inp[i]);
            }
        }
    }

    if (!so.empty()) {
        hauTo.push_back(so);
    }

    while (!phepToan.empty()) {
        hauTo.push_back(string(1, phepToan.top()));
        phepToan.pop();
    }
}

void tinhGiaTri() {
    stack<int> s;

    for (string x : hauTo) {
        if (isdigit(x[0])) {
            s.push(stoi(x));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(tinhToan(a, b, x[0]));
        }
    }

    ans = s.top();
}

int main() {
    cin >> inp;
    trungToSangHauTo();
    tinhGiaTri();
    cout << ans << endl;
    return 0;
}