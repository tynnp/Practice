#include <iostream>
using namespace std;

int main() {
    int test, d, n, x, y, z;
    int arr[1024][1024];
    cin >> test;
    
    while (test--) {
        for (int i = 0; i < 1024; i++)
            for (int j = 0; j < 1024; j++)
                arr[i][j] = 0;

        cin >> d >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;

            for (int a = x - d; a <= x + d; a++) {
                if (a < 0 || a > 1023) continue;

                for (int b = y - d; b <= y + d; b++) {
                    if (b < 0 || b > 1023) continue;
                    arr[a][b] += z;
                }
            }
        }

        int res = -1;
        for (int i = 0; i < 1024; i++)
            for (int j = 0; j < 1024; j++)
                if (arr[i][j] > res) 
                    x = i, y = j, res = arr[i][j];
        
        cout << x << " " << y << " " << res << endl;
    }

    return 0;
}