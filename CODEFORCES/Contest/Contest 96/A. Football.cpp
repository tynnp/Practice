#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    int cnt(1);
    for (int i = 1; i < str.length(); i++) {
        if (str[i-1] == str[i]) cnt++;
        else cnt = 1;
        if (cnt == 7) return true;
    }
    return false;
}

int main() {
    string str;
    cin >> str;
    cout << (check(str) ? "YES" : "NO");
    return 0;
}