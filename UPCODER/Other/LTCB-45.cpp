#include <iostream>
using namespace std;

int main() {
    int n, res = 1;
    cin >> n;
    
    while (n > 0)
        res *= n%10, n /= 10;

    cout << res;
    return 0;
}