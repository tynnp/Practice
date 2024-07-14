#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int cnt = 1, res = 1;
    cin >> str;

    for (int i = 1; i < str.length(); i++) {
        if (str[i-1] == str[i]) cnt++;
        else cnt = 1;
        res = max(cnt, res);
    }

    cout << res;
    return 0;
}