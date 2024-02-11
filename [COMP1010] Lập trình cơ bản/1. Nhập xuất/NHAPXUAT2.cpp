#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; 
    cin >> a >> b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b;
    return 0;
}