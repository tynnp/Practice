#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    getline(cin, s1);
    cin >> s2;
    s1 += s2;

    cout << s1;
    return 0;
}