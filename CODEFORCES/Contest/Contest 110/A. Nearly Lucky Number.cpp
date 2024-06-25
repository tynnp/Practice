#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    int cnt(0);
    for (char c : str) 
        if (c == '4' || c == '7') cnt++;
    return cnt == 4 || cnt == 7;
}

int main() {
    string str;
    cin >> str;
    cout << (check(str) ? "YES" : "NO");
    return 0;
}