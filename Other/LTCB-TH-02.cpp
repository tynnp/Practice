#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    int k = n, res = 0;

    while (k) {
        int x = 0;
        while (x < k) res += pow(10, x), x++;
        k--;
    }

    cout << res;
    return 0;
}