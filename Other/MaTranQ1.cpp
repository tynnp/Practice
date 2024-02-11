#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a; cin >> a;
    int arr[n][n];

    for (int i = n-1; i >= 0; i--) 
        for (int j = n-1; j >= 0; j--)
            arr[n-i-1][n-j-1] = a + i*n + j;

    // for (int i = 0; i < n; i++) 
    //     for (int j = 0; j < n; j++)
    //         cout << arr[i][j] << " ";

    for (int j = 1; j < n; j += 2) {
        for (int i = 0; i < n; i++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }

    int soLeMin = 99999999;
    for (int i = 0; i < n; i++)
        if (arr[i][n-1] < soLeMin && arr[i][n-1] % 2 != 0) 
            soLeMin = arr[i][n-1];
    if (soLeMin == 99999999) cout << "NULL" << endl;
    else cout << soLeMin << endl;

    int tongSoChan = 0;
    for (int i = 0; i <= n-1; i += n-1)
        for (int j = 0; j <= n-1; j += n-1)
            if (arr[i][j] % 2 == 0) tongSoChan += arr[i][j];
    cout << tongSoChan;
    
    return 0;
}