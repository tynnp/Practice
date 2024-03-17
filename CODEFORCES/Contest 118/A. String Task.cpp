#include <bits/stdc++.h>
using namespace std;

bool check(char c) {
    c = tolower(c);
    if (c == 'a') return false;
    if (c == 'o') return false;
    if (c == 'y') return false;
    if (c == 'e') return false;
    if (c == 'u') return false;
    if (c == 'i') return false;
    return true; 
}

int main() {
    string str;
    cin >> str;
    for (char c : str) 
        if (check(c)) cout << '.' << (char) tolower(c);
    return 0;
}