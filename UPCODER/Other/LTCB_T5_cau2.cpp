#include <iostream>
using namespace std;

int main() {
    int m, n; 
    cin >> m >> n;
    if (m%n == 0) cout << m << " chia het cho " << n;
    else if (n%m == 0) cout << n << " chia het cho " << m;
    else if (n%m == 0 && m%n == 0) cout << 1;
    else if (n%m != 0 && m%n != 0) cout << -1;
    return 0;
}