#include <iostream>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    
    int x = a + b + k;
    int y = a + k;
    int z = b + k;
    
    if (y < z) cout << x << z << y;
    else cout << x << y << z;
    
    return 0;
}