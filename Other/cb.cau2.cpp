#include <iostream>
using namespace std;
 
int main() {
    int a, b, c, d, nhi = -1;
    cin >> a >> b >> c >> d;

    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;

    if (nhi < a && a < max) nhi = a;
    if (nhi < b && b < max) nhi = b;
    if (nhi < c && c < max) nhi = c;
    if (nhi < d && d < max) nhi = d;

    (nhi == -1) ? cout << max << " " << max : cout << nhi << " " << max;
    return 0;
}