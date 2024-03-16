#include <iostream>
using namespace std;
 
bool check(int n) {
    int res = 0;

    for (int i = 1; i <= n/2; i++)
        if (n % i == 0) res += i;

    return (res == n && n > 0);
}

int main() {
    int n; 
    cin >> n; 
    double arr[n], index = -1;
    for (double& x : arr) cin >> x;

    for (double x : arr) 
        if (check(x)) {
            index = x; break;
        }

    cout << index;
    return 0;
}