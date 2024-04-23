#include <iostream> 
#include <cmath>
using namespace std;

int main() {
    long long k, n;
    long long val[7];
    cin >> k >> n;
    
    k = k % 10;
    for (int i = 1; i < 7; i++)
        val[i] = (pow(k, i)-1) / (k - 1);
    val[0] = (k == 6 ? val[5] : val[4]);
    
    if (k == 1) cout << n % 10;
    else if (k != 6) cout << val[n % 4] % 10;
    else cout << val[n % 5] % 10;
    
    return 0;
}