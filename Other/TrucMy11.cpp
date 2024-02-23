#include <iostream>
using namespace std;

int main() {
    int n, dp[56];

    for (int i = 0; i < 56; i++) {
        if (i < 4) dp[i] = i;
        else dp[i] = dp[i-1] + dp[i-3];
    }

    while (cin >> n) {
        if (n == 0) break;
        else cout << dp[n] << endl;
    }

    return 0;
}