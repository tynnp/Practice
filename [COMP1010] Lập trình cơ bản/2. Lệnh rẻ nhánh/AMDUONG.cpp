#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x; cin >> x;
    if (x > 0) cout << "DUONG";
    else if (x < 0) cout << "AM";
    else cout << "KHONG";
    return 0;
}