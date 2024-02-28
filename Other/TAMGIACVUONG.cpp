#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(2);
    cout << "Dien tich: " << 0.5*a*b << endl;
    cout << "Canh huyen: " << sqrt(a*a + b*b) << endl;
    return 0;
}