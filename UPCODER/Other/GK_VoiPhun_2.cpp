#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

struct ToaDo {
    int x, y;

    double doDaiVoi(ToaDo other) {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

istream &operator >> (istream &cin, ToaDo &td) {
    cin >> td.x >> td.y;
    return cin;
}

bool operator == (ToaDo a, ToaDo b) {
    return a.x == b.x && a.y == b.y;
}

struct VoiPhun {
    ToaDo O;
    int R;

    double dienTich() {
        return PI*R*R;
    }

    double doDaiVoi(VoiPhun other) {
        return O.doDaiVoi(other.O);
    }
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

double operator + (VoiPhun a, VoiPhun b) {
    return round((a.dienTich() + b.dienTich()) * 1000.0F) / 1000.0F;
}

double operator - (VoiPhun a, VoiPhun b) {
    return round(a.doDaiVoi(b) * 1000.0F) / 1000.0F;
}

string operator == (VoiPhun a, VoiPhun b) {
    if (a.O == b.O && a.R == b.R) return "A trung voi B";
    else return "A khong trung voi B";
}

string operator < (VoiPhun a, VoiPhun b) {
    if (a.dienTich() < b.dienTich()) return "A nho hon B";
    else return "A khong nho hon B";
}

string operator > (VoiPhun a, VoiPhun b) {
    if (a.dienTich() > b.dienTich()) return "A lon hon B";
    else return "A khong lon hon B";
}

int main() {
    VoiPhun a, b;
    cin >> a >> b;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << (a == b) << endl;
    cout << (a < b) << endl;
    cout << (a > b);

    return 0;
}