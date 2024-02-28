#include <iostream>
using namespace std;
 
int main() {
    double a, b, c; 
    cin >> a >> b >> c;

    if (a + b > c && b + c > a && c + a > b) {
        cout << "YES\n";
        if (a == b && a == c) cout << "DEU";
        else if (a == b || b == c || a == c) cout << "CAN";
        else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) cout << "VUONG";
        else cout << "THUONG";

    }else cout << "NO";

    return 0;
}