#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    int i = 0;
    int j = s.size()-1;
    
    while (i < j) {
        if (s[i] != s[j]) 
            return false;
        i += 1, j -= 1;
    }
    
    return true;
}

int main() {
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        ans += check(to_string(i));
    cout << ans;
    return 0;
}