#include <iostream>
using namespace std;

int main() {
    long long n, x, y, z;
    long long a[100007], tong[100007];

    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    tong[0] = 0;
    for (int i = 1; i <= n; i++) 
        tong[i] = tong[i - 1] + a[i];
    
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cin >> y >> z;
        cout << tong[z] - tong[y - 1] << endl;
    }

    return 0;
}
