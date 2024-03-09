#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n+1][n+1];
    memset(arr, 0, sizeof(arr));

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1; 
        arr[b][a] = 1;
    }

    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}