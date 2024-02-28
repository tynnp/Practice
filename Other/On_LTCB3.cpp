#include <iostream>
using namespace std;
 
int main() {
    int a, b, c; 
    cin >> a >> b >> c;
    
    int max = a; 
    if( max < b) max = b;
    if (max < c) max = c;

    int max_nhi = -999;
    if (max_nhi < a && a < max) max_nhi = a;
    if (max_nhi < b && b < max) max_nhi = b;
    if (max_nhi < c && c < max) max_nhi = c;

    cout << max_nhi;
    cout << (max_nhi % 2 == 0 ? " la so chan" : " la so le");
    return 0;
}