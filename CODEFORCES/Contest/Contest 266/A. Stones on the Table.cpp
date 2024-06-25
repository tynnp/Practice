#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    string str;
    cin >> n >> str;
    for (int i = 1; i < str.length(); i++)
        cnt += (str[i-1] == str[i]);
    cout << cnt;
    return 0;
}