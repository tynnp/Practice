#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    for (int i = str.length()-1; i >= 0; i--)
        cout << str[i];

    return 0;
}