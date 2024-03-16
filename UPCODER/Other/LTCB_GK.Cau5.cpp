#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
  
int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c)/2;
        cout << fixed << setprecision(0) << a + b + c << " " << sqrt(p*(p - a)*(p - b)*(p - c));
    } else cout << "Khong phai tam giac";

    return 0;
}