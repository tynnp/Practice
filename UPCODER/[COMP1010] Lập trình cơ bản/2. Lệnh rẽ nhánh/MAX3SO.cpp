#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int max = a, min = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (min > b) min = b;
    if (min > c) min = c;
    cout << max << " " << min;
    return 0;
}