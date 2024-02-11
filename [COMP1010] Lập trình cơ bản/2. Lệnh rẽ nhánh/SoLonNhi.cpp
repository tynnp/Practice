#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;

    int max2 = -999999;
    if (max2 < a && a < max) max2 = a;
    if (max2 < b && b < max) max2 = b;
    if (max2 < c && c < max) max2 = c;
    if (max2 < d && d < max) max2 = d;

    cout << (max2 == -999999 ? -1 : max2);
    return 0;
}