#include <iostream>
#include <stack>
using namespace std;

int main() {
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