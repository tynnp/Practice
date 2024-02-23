#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    while (n > 0)
        cnt += (n%10 % 2 != 0),
        n /= 10;

    cout << cnt;
    return 0;
}