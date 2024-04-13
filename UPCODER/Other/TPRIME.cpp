#include <iostream>
using namespace std;

bool nguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)  
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    int n, cnt(0);
    cin >> n;
    for (int i = 2; i*i <= n; i++)
        if (nguyenTo(i)) cnt++;
    cout << cnt;
    return 0;
}