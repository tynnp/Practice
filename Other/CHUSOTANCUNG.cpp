#include <iostream>
using namespace std;

int main() {
    int a, b, res = 1;
    cin >> a >> b;
    
    a = a % 10;
    
    while (b > 0) {
        if (b & 1) res = (res*a) % 10;
        a = (a*a) % 10;
        b /= 2;
    }
    
    cout << res;
    return 0;
}