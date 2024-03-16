#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    for (char c : str)
        cout << (char) toupper(c);
    return 0;
}