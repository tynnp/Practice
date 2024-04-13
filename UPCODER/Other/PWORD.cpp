#include <iostream>
using namespace std;

int main() {
    string str;
    int res(0);
    cin >> str;
    for (char c : str)
        if (isdigit(c)) res += c - '0';
    cout << res;
    return 0;
}