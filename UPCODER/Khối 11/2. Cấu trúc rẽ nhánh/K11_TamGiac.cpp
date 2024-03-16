#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long double a, b, c, C;
    cin >> a >> b >> C;
    
    if (C == 180) cout << "KHONG PHAI TAM GIAC";
    else {
        C = C*M_PI / 180;
        c = sqrt(a*a + b*b - 2*a*b*cos(C));
        cout << roundf(c*10000)/10000;
    }

    return 0;
}