#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;
    if (max < e) max = e;

    cout << max;
    return 0;
}