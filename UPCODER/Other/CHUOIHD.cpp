#include <iostream>
#include <stack>
using namespace std;

bool check(const string &str) {
    stack<char> s;
    for (const char &c : str) 
        if (s.empty() || c != s.top()) s.push(c);
        else s.pop();
    return s.empty();
}

int main() {
    int N, cnt(0);
    string res("");
    cin >> N;
    
    while (N--) {
        string str;
        cin >> str;
        if (check(str)) 
            res += str + '\n',
            cnt++;
    }
    
    cout << cnt << endl;
    cout << res;
    return 0;
}