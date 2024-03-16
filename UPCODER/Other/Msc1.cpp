#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    string arr[n];
    for (string &x : arr) cin >> x;

    for (string x : arr) {
        if ((x[0] - '0') % 2 == 0)
            res += stoi(x);
    }

    cout << res;
    return 0;
}