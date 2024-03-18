#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n, a(0), b(0);
    cin >> n >> str;

    for (char c : str) {
        if (c == 'A') a++;
        if (c == 'D') b++;
    }

    if (a > b) cout << "Anton";
    else if (a < b) cout << "Danik";
    else cout << "Friendship";

    return 0;
}