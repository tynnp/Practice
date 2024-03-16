#include <iostream>
using namespace std;

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
} 

int bcnn(int a, int b) {
    return a*b/ucln(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << bcnn(a, b);
    return 0;
}