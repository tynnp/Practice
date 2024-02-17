#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) 
        arr[i] = new int[n];

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            arr[i][j] = i == j ? 1 : 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    
    return 0;
}