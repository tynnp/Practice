#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, cnt = 0;
    cin >> a >> b;

    while (a <= b) {
        a *= 3;
        b *= 2;
        cnt += 1;
    }

    cout << cnt;
    return 0;
}