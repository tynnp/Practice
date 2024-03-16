#include <iostream>
using namespace std;

bool kiTu(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str, res = "";
    getline(cin, str);
    bool check = true;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        char tmp = tolower(str[i]);
        if (kiTu(tmp)) res += tmp;
    }

    len = res.length();
    for (int i = 0; i <= len/2; i++) {
        if (res[i] != res[len-1-i]) {
            check = false;
            break;
        }
    }

    cout << (check ? "YES" : "NO");
    return 0;
}