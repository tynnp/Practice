#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<string, int> m;
    cin >> n;

    while (n--) {
        string tmp;
        cin >> tmp;

        if (m.count(tmp) == 0) {
            cout << "OK\n";
            m[tmp] = 1;
        } else {
            cout << tmp << m[tmp] << endl;
            m[tmp] += 1;
        }
    }

    return 0;
}