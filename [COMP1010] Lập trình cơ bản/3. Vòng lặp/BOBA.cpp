#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, sum = 0;
    cin >> n >> m >> k;

    while (n > 0) sum += n%10, n /= 10;
    while (m > 9) m /= 10;
    cout << (sum + m == k ? "Yes" : "No");
    
    return 0;
}