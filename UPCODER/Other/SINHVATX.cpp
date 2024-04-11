#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<long long> sum(91, 0);
    vector<long long> duc(91, 0);
    duc[1] = sum[1] = sum[2] = 1, duc[2] = 0;
    
    cin >> n;
    for (int i = 3; i <= n; i++)
        sum[i] = sum[i-1] + sum[i-2],
        duc[i] = duc[i-1] + duc[i-2];
    
    cout << sum[n] << endl << duc[n];
    return 0;
}