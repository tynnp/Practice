#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
    double S, V; 
    cin >> S >> V;
    double R = sqrt(S);
    double h = 3*V/S;
    cout << fixed << setprecision(4);
    cout << "R = " << R << endl;
    cout << "h = " << h << endl;
    cout << "l = " << sqrt(R*R + h*h);
    return 0;
}