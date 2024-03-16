#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, res = 0;
    cin >> a >> b;

    if (a < 1 || a > 7 || b < 1 || b > 7) cout << "NHAP SAI";
    else {
        if (a == b) res = 0;
        else if (a == 1) res = 400000 + (b-a-1)*300000;
        else if (a > b && b == 1) res = (7-a+b)*300000;
        else if (a > b) res = 400000 + (6-a+b)*300000;
        else res = (b-a) * 300000;
        cout << res;
    }

    return 0;
}