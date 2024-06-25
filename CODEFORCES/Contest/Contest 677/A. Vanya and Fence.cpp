#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, cnt(0);
    cin >> n >> h;

    vector<int> v(n);
    for (int &x : v) cin >> x;

    for (int x : v)
        cnt += (x > h) ? 2 : 1;

    cout << cnt;
    return 0;
}