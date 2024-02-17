#include <iostream>
using namespace std;

void coSo2(int n) {
    if (n < 2) cout << n;
    else {
        coSo2(n / 2);
        cout << n % 2;
    } return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    coSo2(n);
    return 0;
}