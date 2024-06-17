#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    str.erase(remove_if(str.begin(), str.end(), [] (char &c) {
        c = tolower(c);
        return !isalpha(c);
    }), str.end());
    
    stack<char> s;
    for (char c : str) 
        s.push(c);
        
    for (char c : str) {  
        if (s.top() != c) return false;
        s.pop();
    }
    
    return true;
}

int main() {
    string str;
    getline(cin, str);
    cout << (check(str) ? "YES" : "NO");
    return 0;
}