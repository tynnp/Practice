#include <iostream>
using namespace std;
 
int main() {
    int a, b; 
    char c;
    cin >> a >> c >> b;
    if (c == '+') cout << a << c << b << "=" << a + b;
    else cout << a << c << b << "=" << a - b;
    return 0;
}