#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
    double r, h; 
    cin >> r >> h;
    cout << fixed << setprecision(2) << (r + sqrt(r*r + h*h))*3.14*r;
    return 0;
}