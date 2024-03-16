#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Vector {
private:
    int x, y, z;
public:
    Vector();
    Vector(int px, int py, int pz);
    Vector(const Vector& pu);
    int getX(); int getY(); int getZ(); 
    void setX(int px); void setY(int py); void setZ(int pz);
    double F();
    Vector operator + (Vector pv);
    Vector operator - (Vector pv);
};

istream& operator >> (istream& cin, Vector& pu);
ostream& operator << (ostream& cout, Vector& pu);

int main() {
    Vector a, b, res;
    cin >> a >> b;
    cout << a << endl << a.F() << endl;
    cout << b << endl << b.F() << endl;
    res = a + b; cout << res << endl;
    res = a - b; cout << res << endl;
    return 0;
}

Vector::Vector() {
    x = y = z = 0;
}

Vector::Vector(int px, int py, int pz) {
    x = px;
    y = py;
    z = pz;
}

Vector::Vector(const Vector& pu) {
    x = pu.x;
    y = pu.y;
    z = pu.z;
}

void Vector::setX(int px) {
    x = px;
}

int Vector::getX() {
    return x;
}

void Vector::setY(int py) {
    y = py;
}

int Vector::getY() {
    return y;
}

void Vector::setZ(int pz) {
    z = pz;
}

int Vector::getZ() {
    return z;
}

double Vector::F() {
    return roundf(sqrt(x*x + y*y + z*z)*100)/100;
}

Vector Vector::operator + (Vector pv) {
    Vector res;
    res.x = x + pv.x;
    res.y = y + pv.y;
    res.z = z + pv.z;
    return res;
}

Vector Vector::operator - (Vector pv) {
    Vector res;
    res.x = x - pv.x;
    res.y = y - pv.y;
    res.z = z - pv.z;
    return res;
}

istream &operator >> (istream &cin, Vector& pu) {
    int xx, yy, zz;
    cin >> xx >> yy >> zz;
    pu.setX(xx); pu.setY(yy); pu.setZ(zz);
    return cin;
}

ostream &operator << (ostream &cout, Vector& pu) {
    cout << "(" << pu.getX() << "," << pu.getY() << "," << pu.getZ() << ")";
    return cout;
}