#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res(0);
    cin >> n;
    vector<int> a, b;

    while (n--) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    res = b[0] - a[0];
    int sum = res;
    for (int i = 1; i < a.size(); i++) {
        res -= a[i]; sum = max(sum, res);
        res += b[i]; sum = max(sum, res);
    }

    cout << sum;
    return 0;
}