#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, arr[100];
    int tmp, sum = 0;

    while (cin >> tmp) {
        arr[n++] = tmp;
        sum += tmp;
    }

    sort(arr, arr + n);

    if (n < 3) cout << "NO";
    else {
        cout << n << '\n';
        cout << sum << '\n';
        for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    }

    return 0;
}