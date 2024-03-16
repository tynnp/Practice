#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    
    cout << a;
    return 0;
}