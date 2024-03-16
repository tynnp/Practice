#include <iostream>
using namespace std;

int ucln(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int bcnn(int a, int b) {
    return a*b / ucln(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << ucln(a, b) << " " << bcnn(a, b);
    return 0;
}