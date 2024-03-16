#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cin >> n;
    long long arr[n][n];
    fill(&arr[0][0], &arr[0][0] + n * n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][0] = arr[i][i] = 1;
            if (i > 0 && j > 0)
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0)
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}