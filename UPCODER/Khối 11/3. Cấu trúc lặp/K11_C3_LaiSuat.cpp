#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double n, k, res = 0, lai = 0;
    cin >> n >> k;

    if (n < 0 || k < 0) cout << 0;
    else {
        lai = n*0.05, res = lai;
        while (k < 12)
            lai *= 0.05, res += lai, k++;
        cout << res + n;
    }

    return 0;
}