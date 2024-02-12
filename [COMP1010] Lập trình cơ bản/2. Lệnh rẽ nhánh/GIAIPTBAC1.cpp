#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) cout << "VSN";
    else if ((a != 0 && b == 0) || (a == 0 && b != 0)) cout << "VN";
    else cout << fixed << setprecision(2) << (double) -b/a;
    return 0;
}