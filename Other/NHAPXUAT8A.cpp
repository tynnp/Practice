#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    cout << "( " << a << " " << b[0] << " " << c << " )^2= " << a << " ^2 " << b[0] << " 2 " << a << " " << c<< " + "<< c<< " ^2";
    return 0;
}