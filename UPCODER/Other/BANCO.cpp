#include <iostream>
using namespace std;

int arr[20][20];

int main() {
    int n, res(0);
    cin >> n;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        int ngang(0), doc(0);

        for (int j = 0; j < n; j++) {
            int chinh(0), phu(0);
            
            for (int k = i, l = j; k < n; k++, l++) {
                if (arr[k][l] == 1) res = max(res, ++chinh);
                else chinh = 0;

                if (arr[k][n-l-1] == 1) res = max(res, ++phu);
                else phu = 0;
            }

            if (arr[i][j] == 1) res = max(res, ++ngang);
            else ngang = 0;

            if (arr[j][i] == 1) res = max(res, ++doc);
            else doc = 0;
        }
    }

    cout << res;
    return 0;
}