#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1;
    s2 = s1.substr(1, s1.length()-1);
    cout << (char) toupper(s1[0]) << s2;
    return 0;
}