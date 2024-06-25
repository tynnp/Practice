#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, res = "hello";
    int index = 0;
    cin >> str;

    for (char c : str) 
        if (c == res[index]) index++;

    if (index == 5) cout << "YES";
    else cout << "NO";
    return 0;
}