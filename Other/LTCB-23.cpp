#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cnt += (n % i == 0);

    cout << cnt;
    return 0;
}