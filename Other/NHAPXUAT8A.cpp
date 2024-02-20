#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char a, b, c;
    cin >> a >> b >> c;
    cout << "( " << a << " " << b << " " << c << " )^2= " << a << " ^2 " << b << " 2 " << a << " " << c<< " + "<< c<< " ^2";
    return 0;
}