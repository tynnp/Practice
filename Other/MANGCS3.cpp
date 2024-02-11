#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[1000];
    int m, n = 0;

    cin >> m;
    while (cin >> arr[n]) n++;

    for (int i = 0; i < n; i++)
        if (i != m) cout << arr[i] << " ";

    return 0;
}