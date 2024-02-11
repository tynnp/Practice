#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int len = str.size();
    cout << (len < 3 ? -1 : str[len-3]-48);
    return 0;
}