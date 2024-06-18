#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    int len = str.size()/2;
    len += str.size() % 2 == 0 ? 0 : 1;
    string s = str.substr(0, len);
    
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size()-i-1]) 
            return false;
            
    return true;
}

int main() {
    int n, ans = INT_MIN;
    
    while (cin >> n) 
        if (check(to_string(n)) && n > ans)
            ans = n;
            
    cout << ans;
    return 0;
}