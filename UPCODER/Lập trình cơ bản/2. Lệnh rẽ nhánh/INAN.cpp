#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, p, c;
    cin >> t >> p >> c;

    if (t == 1) cout << (long long) p*c;
    else if (t == 2) cout << (long long) (p/2 + p%2)*c;
    return 0;
}