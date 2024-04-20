#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    string str, tmp, res("");
    stack<char> s;
    getline(cin, str);

    stringstream ss(str);
    int sum(0);

    while (ss >> tmp) {
        for (char c : tmp) 
            if (isdigit(c)) sum += c - '0';
            else s.push(c);
        
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }

        res += " ";
    }

    cout << sum << " " << res;
    return 0;
}