#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double x; cin >> x;
    cout << fixed << setprecision(3) << x;
    return 0;
}