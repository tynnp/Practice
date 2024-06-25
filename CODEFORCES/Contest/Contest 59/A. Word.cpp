#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int up = 0, low = 0;
    cin >> str;

    for (char c : str) {
        if (c >= 'a' && c <= 'z') low++;
        else up++;
    }

    if (up > low) for (char c : str) cout << (char) toupper(c);
    else for (char c : str) cout << (char) tolower(c);
    return 0;
}