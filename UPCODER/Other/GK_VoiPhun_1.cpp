#include <iostream>
#include <cmath>
using namespace std;

struct ToaDo {
    int x, y;
};

istream &operator >> (istream &cin, ToaDo &td) {
    cin >> td.x >> td.y;
    return cin;
}

struct VoiPhun {
    ToaDo O;
    int R;
}; 

istream &operator >> (istream &cin, VoiPhun &vp) {
    cin >> vp.O >> vp.R;
    return cin;
}

ostream &operator << (ostream &cout, VoiPhun vp) {
    cout << "(x";
    if (vp.O.x < 0) cout << '+' << abs(vp.O.x);
    else cout << '-' << vp.O.x;

    cout << ")^2+(y";
    if (vp.O.y < 0) cout << '+' << abs(vp.O.y);
    else cout << '-' << vp.O.y;

    cout << ")^2=";
    cout << vp.R*vp.R << endl;
    return cout;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        VoiPhun tmp;
        cin >> tmp;
        cout << tmp;
    }

    return 0;
}