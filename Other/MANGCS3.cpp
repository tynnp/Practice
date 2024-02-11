#include <iostream>
using namespace std;

int main() {
    int arr[1000];
    int m, n = 0;

    cin >> m;
    while (cin >> arr[n]) n++;

    for (int i = 0; i < n; i++)
        if (i != m) cout << arr[i] << " ";

    return 0;
}