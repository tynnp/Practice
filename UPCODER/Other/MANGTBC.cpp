#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n), res(n + 1);
    for (long long &x : arr) cin >> x;

    res[0] = 0;
    for (int i = 1; i < n; i++)
        res[i] = res[i - 1] + arr[i - 1];
    res[n] = res[n - 1] + arr[n - 1];

    for (int i = 1; i <= n; i++)
        res[i] = res[i] / i;

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}