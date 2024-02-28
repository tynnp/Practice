#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    if (n % 3 == 0) cout << n << " chia het cho 3";
    else if (n % 3 == 1) cout << n << " chia 3 du 1";
    else if (n % 3 == 2) cout << n << " chia 3 du 2";
    return 0;
}