#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;

    for (char c : str) 
        if (isalnum(c)) 
            charStack.push(tolower(c));

    for (char c : str) {
        if (isalnum(c)) {
            if (charStack.top() != tolower(c))
                return false;
            charStack.pop();
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; 
    getline(cin, str);
    cout << (isPalindrome(str) ? "YES" : "NO");
    return 0;
}