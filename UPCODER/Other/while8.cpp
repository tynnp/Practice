#include <iostream>
using namespace std;    

bool check(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1 && n < 10;
}

int main() {
    long long n, res(0);
    cin >> n;

    while (n > 0) {
        if (check(n % 10)) res += n%10;
        n /= 10;
    }

    cout << res;
    return 0;
}