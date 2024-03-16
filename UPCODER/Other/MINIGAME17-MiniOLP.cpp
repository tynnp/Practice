#include <iostream>
using namespace std;

int main() {
    string str;
    int res = 0, cnt = 0;
    cin >> str;

    for (char c : str) {
        if (toupper(c) == 'D') {
            cnt += 1;
            res += cnt;
        } else cnt = 0;
    }

    cout << res;
    return 0;
}