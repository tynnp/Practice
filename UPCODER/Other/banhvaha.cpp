#include <iostream>
using namespace std;

int main() {
    long long n, chan = 0, le = 0;
    cin >> n;

    while (n > 0) {
        if (n%10 % 2 == 0) chan += n%10;
        else le += n%10;
        n /= 10;
    }

    cout << chan*le;
    return 0;
}