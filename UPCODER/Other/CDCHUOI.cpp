#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int pos(0), check(0);
    while (pos < str.size()) {
        check = (str[pos] == '1' ? 3 : 2);
        cout << (char) stoi(str.substr(pos, check));
        pos += check;
    }

    return 0;
}