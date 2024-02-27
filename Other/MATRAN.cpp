#include <iostream>
using namespace std;
 
int main() {
    int m, n, a, b; 
    cin >> m >> n;
    int arr[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    cin >> a >> b;
    for (int i = 0; i < m; i++)
        swap(arr[i][a-1], arr[i][b-1]);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}