#include <bits/stdc++.h>
using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), [] (char c) {
        return tolower(c);
    });
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    toLowerCase(s1); 
    toLowerCase(s2);

    if (s1 < s2) cout << -1;
    else if (s1 > s2) cout << 1;
    else cout << 0;

    return 0;
}