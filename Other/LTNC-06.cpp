#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    int arr[n+1];
    arr[1] = arr[2] = arr[3] = 1;
    for (int i = 4; i <= n; i++)
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];

    for (int i = 1; i <= n; i++)
        res += arr[i];

    cout << res;
    return 0;
}