#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= 10; i++)
        cout << n << "x" << i << "=" << n*i << "\n";
    return 0;
}