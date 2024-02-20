#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, res = 0; cin >> n;
    for (int i = 5; i <= n; i += 5)
        res += i;

    cout << res;
    return 0;
}