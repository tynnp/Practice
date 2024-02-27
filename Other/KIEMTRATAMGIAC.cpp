#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
    double a, b, c; 
    cin >> a >> b >> c;

    if (a + b > c && b + c > a && a + c > b) {
        if (a == b && a == c) cout << "deu\n";
        else if (a == b || a == c || b == c) cout << "can\n";
        else if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b) cout << "vuong\n";
        double cv = a + b + c, p = cv/2;
        cout << fixed << setprecision(2);
        cout << "chu vi: " << cv << endl;
        cout << "dien tich: " << sqrt(p*(p - a)*(p - b)*(p - c));
    } else cout << "NO";
    
    return 0;
}