#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if (n == 0) cout << 0;
    else {
        int len = log10(n);
        int first = 0;

        for (int i = len; i > 0; i--) {
            if (int(n/pow(10, i)) % 10 < int(n/pow(10, i-1)) % 10 || i == 1) {
                cout << int(first*pow(10, i) + n % int(pow(10, i)));
                break;
            } else first = first*10 + int(n/pow(10, i)) % 10;
        }
    }
    return 0;
}