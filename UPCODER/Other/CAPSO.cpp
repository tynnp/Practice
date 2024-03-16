#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c;
    long d, e, f;

    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0) break;
        if (b - a == c - b) {
            d = c + (c - b);
            e = d + (d - c);
            f = e + (e - d);
            cout << "CSC " << a << " " << b << " " << c << " "  << d << " "  << e << " "  << f << " = " << a + b + c + d + e + f << endl;
        
        } else if ((float) b / a == (float) c / b){
            d = c * (c / b);
            e = d * (d / c);
            f = e * (e / d);
            cout << "CSN " << a << " " << b << " " << c << " "  << d << " "  << e << " "  << f << " = " << a + b + c + d + e + f << endl;
        
        }
        else cout << "khong phai CAP SO" << endl;
    }

    return 0;
}