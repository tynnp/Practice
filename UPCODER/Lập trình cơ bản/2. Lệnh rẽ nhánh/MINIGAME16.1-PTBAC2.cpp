#include <iostream>
#include <iomanip>
#include <cmath>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed << setprecision(10);
    double a, b, c; cin >> a >> b >> c;
    
    if (a == 0) {
        if (b == 0) cout << (c == 0 ? -1 : 0);
        else cout << 1 << endl << ((-1.0*c)/b == 0 ? 0.0 : (-1.0*c)/b);
    } else {
        double delta = b*b - 4*a*c;
        if (delta < 0) cout << 0;
        else if (delta == 0) cout << 1 << endl << (-1.0*b/(2*a) == 0 ? 0.0 :-1.0*b/(2*a));
        else {
            double x1 = (double) (-1.0*b + sqrt(delta)) / (2*a);
            double x2 = (double) (-1.0*b - sqrt(delta)) / (2*a);
            if (x1 > x2) swap(x1, x2);
            cout << 2 << endl << (x1 == 0 ? 0.0 : x1) << endl << (x2 == 0 ? 0.0 : x2);
        } 
    }   
    
    return 0;
}