#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    vector<long long> divisors;
    cin >> n >> k;
    
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    if (k <= divisors.size()) {
        cout << divisors[k - 1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
