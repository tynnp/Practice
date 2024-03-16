#include <iostream>
#define endl '\n'
using namespace std;

bool checkNT(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int tongCS(int n) {
    if (n == 0) return 0;
    return n%10 + tongCS(n/10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a; cin >> a;
    int arr[n][n];

    for (int i = 0; i < n; i++) 
        for (int j = n - 1; j >= 0; j--)
            arr[i][j] = a + i*n*2 + (n-1-j)*2;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int j = 0; j < n; j += 2) 
        for (int i = 0; i < n; i++) 
            cout << arr[i][j] << " ";

    int index = 0, chanLonNhat = -99999999;
    for (index; index < n; index += 2);

    for (int i = 0; i < n; i++)
        if (arr[i][index-2] % 2 == 0 && arr[i][index-2] > chanLonNhat)
            chanLonNhat = arr[i][index-2];
    if (chanLonNhat == -99999999) cout << endl << "NULL" << endl;
    else cout << endl << chanLonNhat << endl;

    if (n == 1) {
        cout << "NULL";
        return 0;
    }
    bool check = true;

    for (int i = 0; i < n; i++) {
        if (checkNT(tongCS(arr[n-i-1][i]))) {
            cout << "(" << n-i << "," << i+1 << ")";
            check = false;
        }
    }

    if(check) cout << "NULL";
    return 0;
}