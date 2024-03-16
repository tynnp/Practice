#include <iostream>
#include <cmath>
using namespace std;

bool chinhPhuong(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << (chinhPhuong(n) ? "yes" : "no");
    return 0;
}