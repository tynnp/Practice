#include <iostream>
#include <vector>
using namespace std;

int tong(int n) {
    int res(0);
    while (n > 0)
        res += n % 10,
        n /= 10;
    return res;
}

int main() {
    int n, h, cnt(0);
    cin >> n >> h;

    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= n; i++)
        if (prime[i])
            for (int j = i*i; j <= n; j += i)
                prime[j] = false;

    for (int i = 0; i < n; i++)
        if (prime[i] && tong(i) == h) {
            cnt += 1;
            cout << i << endl;
        }

    cout << cnt;
    return 0;
}