#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tong = 0; cin >> n;
    for (int i = 1; i <= n; i++)    
        tong += i;
    cout << tong;
    return 0;
}