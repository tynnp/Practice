#include <iostream>
#include <cmath>
using namespace std;

bool cp(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int res = 0, n = 0;
    int arr[10000];
    while (cin >> arr[n]) n++;

    for (int i = 0; i < n; i++)
        if (cp(arr[i])) res += arr[i];
    cout << res;

    return 0;
}