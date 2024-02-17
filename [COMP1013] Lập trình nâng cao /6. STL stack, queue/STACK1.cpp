#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; 
    getline(cin, str);
    stack<char> charStack;

    for (char c : str) {
        if (c == '*' && !charStack.empty()) {
            cout << charStack.top();
            charStack.pop();
        } else if (c != '*')
            charStack.push(c); 
    }

    return 0;
}