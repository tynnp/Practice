#include <iostream>
using namespace std;

bool palindrom(string str, int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return palindrom(str, start + 1, end - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test; cin >> test;
    while (test--) {
        string str; cin >> str;
        if (palindrom(str, 0, str.length()-1))  
            cout << str << " ";
    }
    return 0;
}