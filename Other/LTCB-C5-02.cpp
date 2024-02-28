#include <iostream>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    int arr[n][m], res = 0;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            res += arr[i][j];

    cout << res;
    return 0;
}