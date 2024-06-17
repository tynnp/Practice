#include <bits/stdc++.h>
using namespace std;

string decimal_to_binary(int n) {
    if (n == 0) return "0";
    stack<char> s;
    string ans("");
    
    while (n) {
        s.push(n % 2 + '0');
        n /= 2;
    }
    
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << decimal_to_binary(n);
    return 0;
}