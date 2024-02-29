// Còn sai 1 test
#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    bool checkNULL = true;
    bool checkEndl = false;
    cin >> m >> n >> k;
    int arr[m+1][n+1];

    for (int i = 0; i <= m; i++)
        arr[i][0] = 0;
    for (int i = 0; i <= n; i++)
        arr[0][i] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == k) {
                arr[0][j] = 1;
                arr[i][0] = 1;
            } 
        }
    }

    for (int i = 1; i <= m; i++) {
        checkEndl = false;
        for (int j = 1; j <= n; j++) {
            if (arr[0][j] || arr[i][0]) continue;
            cout << arr[i][j] << " ";
            checkNULL = false;
            checkEndl = true;
        }
        if (checkEndl) cout << endl;
    }

    if (checkNULL) cout << "Null";
    return 0;
}