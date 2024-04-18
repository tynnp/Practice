#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int f[n+1];
    f[1] = f[2] = 1;

    for (int i = 1; i < 3 && i <= n; i++)
        cout << "F[" << i << "] = " << f[i] << endl;

    for (int i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
        cout << "F[" << i << "] = " << f[i] << endl;
    }

    return 0;
}