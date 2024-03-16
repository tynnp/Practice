#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    int t; 
    double a, n, x, A, res = 0;
    cin >> t;

    if (t == 1) {
        cin >> a; 
        res = a;
    } else if (t == 2) {
        cin >> x >> A;
        res = x*A;
    } else {
        cin >> x >> A >> n >> a;
        res = x*A + n*a;
    } 

    cout << fixed << setprecision(2) << res;
    return 0;
}