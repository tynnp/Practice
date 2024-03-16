#include <iostream>
using namespace std;

int main() {
    double a, b, c; 
    cin >> a >> b >> c;
    if (a + b > c & a + c > b && b + c > a) {
        if (a == b && b == c) cout << "deu";
        else if (a == b || a == c || b == c) cout << "can";
        else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) cout << "vuong";
        else cout << "tam giac binh thuong";
    } else cout << -1;
    return 0;
}