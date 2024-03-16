#include <iostream>
using namespace std;

bool check(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    int n;
    cin >> n;
    cout << check(n);
    return 0;
}