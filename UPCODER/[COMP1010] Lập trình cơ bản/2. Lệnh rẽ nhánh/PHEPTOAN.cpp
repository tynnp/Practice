#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    char c; cin >> c;

    cout << a << c << b << "=";
    switch (c) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '%': cout << a % b; break;
    }
    return 0;
}