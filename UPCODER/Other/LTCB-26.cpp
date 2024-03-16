#include <iostream>
using namespace std;

int main() {
    int n, res = 1; cin >> n;
    for (int i = 1; i <= n; i += 2) 
        if (n % i == 0) res *= i;
    cout << res;
    return 0;
}