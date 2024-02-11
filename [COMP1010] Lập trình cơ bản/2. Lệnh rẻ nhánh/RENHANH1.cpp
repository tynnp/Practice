#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if (n % 3 == 0) cout << n << " chia het cho 3";
    else cout << n << " chia 3 du " << n % 3;
    return 0;
}