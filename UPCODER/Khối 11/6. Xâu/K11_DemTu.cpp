#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);
    int cnt = 1;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') break;
        if (str[i] == ' ') str.erase(i--, 1);
    }

    for (int i = str.length()-1; i >= 0; i--) {
        if (str[i] != ' ') break;
        if (str[i] == ' ') str.erase(i, 1);
    }

    for (int i = 1; i < str.length(); i++)
        cnt += (str[i-1] != ' ' && str[i] == ' ');

    cout << cnt;
    return 0;
}