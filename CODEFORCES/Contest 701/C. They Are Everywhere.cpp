#include <bits/stdc++.h>
using namespace std;

int main() {
    int len, ans = INT_MAX;
    string s;
    map<char, int> m;
    
    cin >> len >> s;
    for (auto c : s) m[c]++;
    
    int i = 0, j = 0, poke = m.size();
    
    m.clear();
    while (i < len) {
        while (j < len && m.size() < poke) 
            m[s[j]]++, j++;
        
        if (m.size() == poke) 
            ans = min(ans, j - i);
        
        if (m[s[i]] == 1) m.erase(s[i]);
        else m[s[i]]--;
        
        i++;
    }
    
    cout << ans;
    return 0;
}