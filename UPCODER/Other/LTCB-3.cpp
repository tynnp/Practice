#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double n, res = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        res += 1.0/i;
    
    cout << setprecision(3) << res;
    return 0;
}