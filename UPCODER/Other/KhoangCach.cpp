#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
    double a, b, c, d; 
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(2) << sqrt(pow(c - a, 2) + pow(d - b, 2));
    return 0;
}