#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, num = 1;
    cin >> n >> m;
    int row = 0, arr[n][m];

    while (row != n) {
        if (row % 2 == 0) {
            for (int i = 0; i < m; i++)
                arr[row][i] = num++;
        } else {
            for (int i = m-1; i >= 0; i--)
                arr[row][i] = num++;
        }
        row++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}