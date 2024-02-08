#include <iostream>
#include <stack>
using namespace std;

bool check(string str) {
    stack<char> charStack;
    if (str.length() == 0) return true;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') charStack.push(c);
        else if (!charStack.empty()) {
            char top = charStack.top(); 
            charStack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                return false;
        } else return false;
    }
    return charStack.empty();
}

int main() {
    string str;
    getline(cin, str);
    cout << (check(str) ? "yes" : "no"); 
    return 0;
}