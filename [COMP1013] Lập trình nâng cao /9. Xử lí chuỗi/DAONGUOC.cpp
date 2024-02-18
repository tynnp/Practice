#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int index = 0;

    if (str[0] == '-') {
        str[0] = '\0';
        cout << "-";
        index = 1;
    }

    for (int i = str.length()-1; i >= index; i--)
        cout << str[i];

    return 0;
}