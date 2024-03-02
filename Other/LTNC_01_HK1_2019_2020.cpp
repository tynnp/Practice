#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) 
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i < j) res += arr[i][j];
        }

    cout << res;
    return 0;
}