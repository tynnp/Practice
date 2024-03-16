#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int len = str.length();
    cout << (len > 3 ? str[len-4] - 48 : -1);
    return 0;
}