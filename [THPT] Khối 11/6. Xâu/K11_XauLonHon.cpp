#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1 == s2) cout << "Hai xau bang nhau";
    else cout << (s1 > s2 ? s1 : s2);

    return 0;
}