#include <iostream>
using namespace std;
 
int main() {
    int a, b, c; 
    cin >> a >> b >> c;

    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;

    int max2 = -10e6;
    if (max2 < a && a < max) max2 = a;
    if (max2 < b && b < max) max2 = b;
    if (max2 < c && c < max) max2 = c;
    if (a == b && b == c) max2 = max;
    
    (max2 & 1) ? cout << max2 << " la so le" : cout << max2 << " la so chan";
    return 0;
}