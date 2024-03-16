#include <iostream>
using namespace std;

int main() {
    int arr[3][3], a, b, c, d, e, f;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    a = arr[0][0] * arr[1][1] * arr[2][2];
    b = arr[0][1] * arr[1][2] * arr[2][0];
    c = arr[1][0] * arr[2][1] * arr[0][2];
    d = arr[0][2] * arr[1][1] * arr[2][0];
    e = arr[0][1] * arr[1][0] * arr[2][2];
    f = arr[1][2] * arr[2][1] * arr[0][0];

    cout << (a + b + c) - (d + e + f);
    return 0;
}