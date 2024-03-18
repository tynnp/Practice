#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (str[i] == str[j]) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    while (!check(to_string(++n)));
    cout << n;
}