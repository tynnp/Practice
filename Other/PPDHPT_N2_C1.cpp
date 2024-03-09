#include <iostream>
#include <cmath>
using namespace std;

struct Diem {
    int x; 
    int y;

    Diem doiXungO() {
        Diem res;
        res.x = -x;
        res.y = -y;
        return res;
    }

    Diem doiXungX() {
        Diem res;
        res.x = x;
        res.y = -y;
        return res;
    }

    Diem doiXungY() {
        Diem res;
        res.x = -x;
        res.y = y;
        return res;
    }

    double doDaiOf(Diem other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    friend istream &operator >> (istream &in, Diem &d) {
        in >> d.x >> d.y;
        return in;
    }

    friend ostream &operator << (ostream &out, Diem d) {
        out << "(" << d.x << ", " << d.y << ")";
        return out;
    }
};

int main() {
    Diem a, b;
    int k;
    cin >> a >> b >> k;

    cout << a << endl;
    cout << b << endl;
    cout << a.doDaiOf(b) << endl;

    if (k == 0) cout << a.doiXungO();
    else if (k == 1) cout << a.doiXungX();
    else if (k == 2) cout << a.doiXungY();

    return 0;
} 