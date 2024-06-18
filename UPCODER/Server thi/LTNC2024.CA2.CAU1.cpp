#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    string s = to_string(n);
    int len = s.size();
    if (len < 2) return false;
    
    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len-i-1]) return false;
        if ((s[i] - '0') & 1) return false;
    }
    
    return true;
}

int main() {
    int n;
    vector<int> v;
    
    while (cin >> n)
        v.push_back(n);
        
    for (int x : v)
        if (check(x)) continue;
        else cout << x << " ";
        
    return 0;
}